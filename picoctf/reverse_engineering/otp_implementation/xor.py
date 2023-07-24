otp="09658219efa384c9147175f3825347315eddb290f2e0c4c3f0e87eb57e3647bb7b6458cc2b381c45f23ec529e77645a23cdd"
flag="790ce176acf7c2b277040687b23e185b2bb0d0fcc1939bf782db10c1210218dc4b2b3c931a5c2f04ad5aa711d04175920aa0"

flag_decoded=""

for i in range(0,100,2):
  hex_value_otp = int(otp[i:i+2],16)
  hex_value_flag = int(flag[i:i+2],16)
  xor_value = hex_value_otp ^ hex_value_flag
  flag_decoded += chr(xor_value)

print(flag_decoded)
