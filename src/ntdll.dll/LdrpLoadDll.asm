.text:000000000001733C ; __unwind { // __GSHandlerCheck
.text:000000000001733C                 push    rbp ; LdrpLoadDll start 40 55 53 56 57 41 56 41 57 48 8D 6C 24 88
.text:000000000001733E                 push    rbx
.text:000000000001733F                 push    rsi
.text:0000000000017340                 push    rdi
.text:0000000000017341                 push    r14
.text:0000000000017343                 push    r15
.text:0000000000017345                 lea     rbp, [rsp-78h]
.text:000000000001734A                 sub     rsp, 178h
.text:0000000000017351                 mov     rax, cs:__security_cookie
.text:0000000000017358                 xor     rax, rsp
.text:000000000001735B                 mov     [rbp+0A0h+var_40], rax
.text:000000000001735F                 mov     rdi, rdx
.text:0000000000017362                 mov     [rsp+1A0h+var_160], r8d
.text:0000000000017367                 mov     rdx, rcx
.text:000000000001736A                 mov     rbx, rcx
.text:000000000001736D                 xor     ecx, ecx
.text:000000000001736F                 mov     r8d, 14A8h
.text:0000000000017375                 mov     rsi, r9
.text:0000000000017378                 call    LdrpLogDllState
.text:000000000001737D                 lea     rax, [rsp+1A0h+var_140]
.text:0000000000017382                 mov     [rsp+1A0h+var_150], 1000000h
.text:000000000001738A                 xor     r14d, r14d
.text:000000000001738D                 mov     [rsp+1A0h+var_148], rax
.text:0000000000017392                 lea     r9, [rsp+1A0h+var_160]
.text:0000000000017397                 mov     [rsp+1A0h+var_140], r14w
.text:000000000001739D                 xor     r8d, r8d
.text:00000000000173A0                 lea     rdx, [rsp+1A0h+var_150]
.text:00000000000173A5                 mov     rcx, rbx
.text:00000000000173A8                 call    LdrpPreprocessDllName
.text:00000000000173AD                 mov     [rsp+1A0h+var_158], eax
.text:00000000000173B1                 test    eax, eax
.text:00000000000173B3                 js      short loc_173E4
.text:00000000000173B5                 mov     r8d, [rsp+1A0h+var_160]
.text:00000000000173BA                 lea     rax, [rsp+1A0h+var_158]
.text:00000000000173BF                 mov     [rsp+1A0h+var_168], rax
.text:00000000000173C4                 lea     r9d, [r14+4]
.text:00000000000173C8                 mov     [rsp+1A0h+var_170], rsi
.text:00000000000173CD                 lea     rcx, [rsp+1A0h+var_150]
.text:00000000000173D2                 mov     [rsp+1A0h+var_178], r14
.text:00000000000173D7                 mov     rdx, rdi
.text:00000000000173DA                 mov     [rsp+1A0h+var_180], r14
.text:00000000000173DF                 call    LdrpLoadDllInternal
