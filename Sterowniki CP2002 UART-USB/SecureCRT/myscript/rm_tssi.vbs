#$language = "VBScript"
#$interface = "1.0"

Sub main
  crt.Screen.Send "AT+EEP=6e,ffff" & VbCr
  crt.Screen.WaitForString "+ok"
  crt.Screen.Send "AT+EEP=70,ffff" & VbCr
  crt.Screen.WaitForString "+ok"
  crt.Screen.Send "AT+EEP=72,ffff" & VbCr
  crt.Screen.WaitForString "+ok"
  crt.Screen.Send "AT+EEP=74,ffff" & VbCr
  crt.Screen.WaitForString "+ok"
End Sub
