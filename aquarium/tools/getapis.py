import os
import sys

def getapis(codedir):
    f=open( codedir ,'r')
    for v in f:

        buf = v.strip()
        if(buf[:9] == 'AQUAENTRY'):
            s1 = buf.index('(')
            s2 = buf.index(')',s1)
            api = buf[s1+1:s2]
            x = api.split(',')
            if len(x) == 2:
                print('*(DWORD*)&Aqua%s = (DWORD)::GetProcAddress(lib,\"Aqua%s\");'%(x[1].strip(),x[1].strip()))
            else :
                 print('*(DWORD*)&Aqua%s%s = (DWORD)::GetProcAddress(lib,\"Aqua%s%s\");'%(x[1].strip(),x[2].strip(),x[1].strip(),x[2].strip()))
        pass
    pass
    f.close()

if __name__ == "__main__":
    getapis("F:\\Studio\\Aquariuscef\\aquarium\\src\\cef\\aqua_download.h")
