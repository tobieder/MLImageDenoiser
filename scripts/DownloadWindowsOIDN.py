import os
import requests
import shutil
import zipfile

filepath = '../vendor/'

filename = 'oidn-1.4.1.x64.vc14.windows'
url = 'https://github.com/OpenImageDenoise/oidn/releases/download/v1.4.1/' + filename + '.zip'
r = requests.get(url, allow_redirects=True)

open('oidn-windows.zip', 'wb').write(r.content)

with zipfile.ZipFile("oidn-windows.zip", "r") as zip_ref:
    zip_ref.extractall("")

os.rename(filename, "oidn-windows")
os.remove("oidn-windows.zip")

shutil.move("oidn-windows", filepath + "oidn-windows")