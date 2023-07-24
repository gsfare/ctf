myexefile="./otp"

correct_answer = "adpjkoadapekldmpbjhjhbaghlfldbhjdalgnbeedheenfoeddabpmdnliokcahomdphbcleipfgibjdcgmjcmadaomiakpdjcni"
valid_chars = "0123456789abcdef"

gdb.execute("set debuginfod enabled off")
gdb.execute("file " + myexefile)
gdb.execute("set pagination off")

ax = gdb.Breakpoint("*(&main+431)")
# bx = gdb.Breakpoint("test_failed")

# here the program will break, so we can do:

correct_part = ""
unknown_part = ""
i=0
while i<100:
  for c in valid_chars:
    unknown_part = correct_part
    for j in range(100-len(correct_part)):
      unknown_part = unknown_part + c

    gdb.execute("run " + unknown_part)
    obfuscated_answer = gdb.parse_and_eval("(char[100])*(char *)($rbp-0x70)").string()

    if obfuscated_answer[i] == correct_answer[i]:
      correct_part = correct_part + c
      i += 1
      break
  print(obfuscated_answer)
print("KEY FOUND: " + correct_part)
