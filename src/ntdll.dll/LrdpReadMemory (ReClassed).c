__int64 LdrpReadMemory(__int64 lpBaseAddress, __int64 lpBuffer, __int64 dwSize, __int64 lpNumberOfBytesRead)
{
  __int64 result; // rax
  __int64 bytesRead; // [rsp+40h] [rbp+8h]

  result = (*(__int64 (__fastcall **)(_QWORD))(lpBaseAddress + 8))(*(_QWORD *)lpBaseAddress);
  if ((int)result >= 0)
    return lpNumberOfBytesRead != bytesRead ? 0x8000000D : 0;
  return result;
}
