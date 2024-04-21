.text:0000000000001379 loc_1379:                               ; CODE XREF: LdrpReadMemory+25↑j ; 48 83 C4 ? 5B C3 CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC 48 8B C4 // Wildcards
.text:0000000000001379                 add     rsp, 30h
.text:000000000000137D                 pop     rbx
.text:000000000000137E                 retn
.text:000000000000137E ; ---------------------------------------------------------------------------
.text:000000000000137F                 db 0CCh
.text:000000000000137F LdrpReadMemory  endp
.text:000000000000137F
.text:0000000000001380 byte_1380       db 10h dup(0CCh)        ; DATA XREF: .pdata:0000000000172024↓o
.text:0000000000001390
.text:0000000000001390 ; =============== S U B R O U T I N E =======================================
.text:0000000000001390
.text:0000000000001390
.text:0000000000001390 LdrpProtectedCopyMemory proc near       ; DATA XREF: LdrQueryProcessModuleInformationEx+35↓o
.text:0000000000001390                                         ; LdrQueryProcessModuleInformationEx2+35↓o ...
.text:0000000000001390
.text:0000000000001390 arg_0           = qword ptr  8
.text:0000000000001390 arg_10          = qword ptr  18h
.text:0000000000001390 arg_18          = qword ptr  20h
.text:0000000000001390 arg_20          = qword ptr  28h

; Pseudocode-A
__int64 __fastcall LdrpReadMemory(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // rax
  __int64 v6; // [rsp+40h] [rbp+8h]

  result = (*(__int64 (__fastcall **)(_QWORD))(a1 + 8))(*(_QWORD *)a1);
  if ( (int)result >= 0 )
    return a4 != v6 ? 0x8000000D : 0;
  return result;
}
