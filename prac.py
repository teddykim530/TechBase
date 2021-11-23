import os
import hashlib, glob

def file2md5(filename):
    md5 = hashlib.md5()
    with open(filename, 'rb') as f:

        for chunk in iter(lambda: f.read(8192), ''):
            md5.update(chunk)

    return md5.hexdigest()

path = 'C:\\Users\\teddy\\files' #폴더 경로 입력, 문자열로 입력받음
array = os.listdir(path) #경로에 있는 파일들의 리스트를 가져옴

i=0
for path, dirs, files in os.walk(path): #하위 디렉토리를 검색해주는 os.walk 모듈을 사용    
    for file in files: #input 디렉터리 안에 있는 모든 파일을 출력(폴더안의 폴더 또한 해당)
        print (os.path.join(path,file))
        flist = glob.glob(os.path.join(path,file))

        for i in flist:
            print (i, os.path.getsize(i),file2md5(i))
            
            
            
            import os

path = "C:/Users/teddy/files"
file_list = os.listdir(path)
file_list_exe = [file for file in file_list if file.endswith(".exe")]

print ("exe file list: {}".format(file_list_exe))