import platform
import os

print("Setting up ML Image Denoiser.")

platform_name = platform.system()

if platform_name == 'Windows':
    print("Your platform is Windows. Downloading according binaries.")
    os.system("DownloadWindowsOIDN.py 1")
    print("Download complete!")
elif platform_name == 'Linux':
    print("Your platform is Linux. Downloading according binaries.")
    os.system("DownloadLinuxOIDN.py 1")
    print("Download complete!")
else:
    print("Operating System not supported!")