import os
import requests
import shutil
import tarfile

filepath = '../vendor/'

filename = 'oidn-1.4.1.x86_64.linux'
url = 'https://github.com/OpenImageDenoise/oidn/releases/download/v1.4.1/' + filename + '.tar.gz'
r = requests.get(url, allow_redirects=True)

open('oidn-linux.tar.gz', 'wb').write(r.content)

tar = tarfile.open('oidn-linux.tar.gz', "r:gz")
tar.extractall()
tar.close()

os.rename(filename, "oidn-linux")
os.remove("oidn-linux.tar.gz")

shutil.move("oidn-linux", filepath + "oidn-linux")