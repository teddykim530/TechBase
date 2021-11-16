import os

os.system('C:\\Users\\teddy\\source\\repos\\Project4\\x64\\Debug\\Project4.exe')

import paramiko

try:
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy)
    ssh.connect("127.0.0.1", port="22", username="teddy", password="gusdn147")
    print("connected!!")
    
    stdin, stdout, stderr = ssh.exec_command("cd 문서 ; gcc -o linuxs.exe linuxs.c ; ./linuxs.exe")
    lines = stdout.readlines()
    resultData = ''.join(lines)
    
    print(resultData)
                                                                            
    ssh.close()
    
except Exception as err:
        print(err)