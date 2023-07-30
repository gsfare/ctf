flag_plain="picoCTF{this_is_a_flag1}"
flag_enc="picoCTF{w1{1wq8/7376j.:}"

def encode(flag):
  flag_copy = list(flag)
  for i in range(8,17):
    if i & 1 == 0:
      flag_copy[i] = chr(ord(flag[i]) + 5)
    else:
      flag_copy[i] = chr(ord(flag[i]) - 2)
  return("".join(flag_copy))

def decode(flag):
  flag_copy = list(flag)
  for i in range(8,23):
    if i & 1 == 0:
      flag_copy[i] = chr(ord(flag[i]) - 5)
    else:
      flag_copy[i] = chr(ord(flag[i]) + 2)
  return("".join(flag_copy))

flag = decode(flag_enc)
print(flag)
