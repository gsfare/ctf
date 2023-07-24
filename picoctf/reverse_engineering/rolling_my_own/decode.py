flag = "57456a4d614c70476b6d6e6e6a4f5670367064656c694752736c787a6563764d"

password = ""
for i in range(0,64,2):
  password += chr(int(flag[i:i+2],16))

print(password)
