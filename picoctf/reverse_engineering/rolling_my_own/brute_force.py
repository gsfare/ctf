import itertools
import subprocess
import getpass

def run_executable_with_password(executable_path, password):
    # Prepare the command to run the executable
    cmd = [executable_path]

    try:
        # Start the process with stdin connected to a PIPE
        process = subprocess.Popen(cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

        # Send the password as input to the executable
        process.stdin.write(password + "\n")
        process.stdin.flush()

        # Get the output and error messages from the executable
        output, error = process.communicate()

        # Check the process return code to see if it was successful
        if process.returncode == 0:
            print(f"Password found: {password}")
            print("Executable ran successfully.")
            print("Executable Output:")
            print(output)
        else:
            print(f"Password failed: {password}")
            if error:
                print("Executable Error:")
                print(error)

    except FileNotFoundError:
        print("Error: Executable not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    # Replace "path/to/your/executable" with the actual path to your executable
    executable_path = "./remote"

    # Define the characters to use for password generation
    characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

    # Define the maximum password length
    max_length = 14

    # Loop through all possible combinations of characters and lengths
    for length in range(1, max_length + 1):
        for password in itertools.product(characters, repeat=length):
            password = "D1v1".join(password)
            run_executable_with_password(executable_path, password)
