#!/usr/bin/env python2.7
#
#          All In One Tool For Penetration Testing 
#           Authors : Fedy Wesleti , Mohamed Nour 
#
import sys
import os
import subprocess
from commands import *
########################## 
#Variables
yes = set(['yes','y', 'ye', ''])
no = set(['no','n'])



##########################

#this is the big menu funtion 
def menu():
    print """
  ########  ######## ##    ## ########   #######  ##     ## 
  ##     ## ##       ###   ## ##     ## ##     ##  ##   ##  
  ##     ## ##       ####  ## ##     ## ##     ##   ## ##   
  ########  ######   ## ## ## ########  ##     ##    ###    
  ##        ##       ##  #### ##     ## ##     ##   ## ##   
  ##        ##       ##   ### ##     ## ##     ##  ##   ##  
  ##        ######## ##    ## ########   #######  ##     ##  v1.0  
                                  Pentesting Tools Auto-Downloader 
 
  [+]       Coded BY Mohamed Nour & Fedy Weslety        [+] 
  [+]          FB/CEH.TN    ~~   FB/mohamed.zeus.0      [+] 
  [+]             Greetz To All Pentesters              [+] 

Select from the menu:

1 : Information Gathering
2 : Password Attacks
3 : Wireless Testing
4 : Exploitation Tools
5 : Sniffing & Spoofing
99 : Exit

"""
    choice = input("selet a number :")
    choice = int(choice)
    if choice == 1:
        info()
    elif choice == 2:
        passwd()
    elif choice == 3:
        wire()
    elif choice == 4:
        exp()
    elif choice == 5:
        snif()
    elif choice == 99:
        os.system('clear'),sys.exit();
#end of function
##########################
#nmap function 
def nmap():
    print("this step will download and install nmap ")
    print("yes or no ")
    choice7 = raw_input()
    if choice7 in yes :
        os.system("wget https://nmap.org/dist/nmap-7.01.tar.bz2")
        os.system("bzip2 -cd nmap-7.01.tar.bz2 | tar xvf -")
        os.system("cd nmap-7.01")
        os.system("./configure")
        os.system("make")
        os.system("su root")
        os.system("make install")
    elif choice7 in no :
        info()
####################################
#jboss-autopwn
def jboss():
    os.system('clear')
    print ("This JBoss script deploys a JSP shell on the target JBoss AS server. Once")
    print ("deployed, the script uses its upload and command execution capability to")
    print ("provide an interactive session.")
    print ("")
    print (" this will install jboss-autopwn") 
    print ("usage : ./e.sh target_ip tcp_port ")
    choice9 = raw_input("yes / no :")
    if choice9 in yes:
        os.system("git clone https://github.com/SpiderLabs/jboss-autopwn.git"),sys.exit();
    elif choice9 in no:
        os.system('clear'); exp()
#sqlmap 
def sqlmap():
    print (" this will install sqlmap ")
    print ("usage : python sqlmap.py -h")
    choice8 = input("yes or no :")
    if choice8 in yes:
        os.system("git clone https://github.com/sqlmapproject/sqlmap.git sqlmap-dev")
    elif choice8 in no:
        os.system('clear'); info()

#setoolkit 
def setoolkit():
    print ("The Social-Engineer Toolkit is an open-source penetration testing framework")
    print(") designed for social engineering. SET has a number of custom attack vectors that ")
    print(" allow you to make a believable attack quickly. SET is a product of TrustedSec, LLC  ")
    print("an information security consulting firm located in Cleveland, Ohio.")
    print("")
    choiceset = raw_input("y / n :")
    if choiceset in yes:
        os.system("git clone https://github.com/trustedsec/social-engineer-toolkit.git");os.system("cd social-engineer-toolkit");os.system("python setup.py")
    if choiceset in no:
        os.system("clear"); info()
#cupp 
def cupp():
    print("cupp is a password list generator ")
    print("Usage: python cupp.py -h")
    print("yes or now")
    choicecupp = raw_input("y / n :")
    
    if choicecupp in yes:
        os.system("git clone https://github.com/Mebus/cupp.git");os.system("cd cupp")
    elif choicecupp in no:
        os.system("clear"); passwd()
#ncrack 
def ncrack():
    print("A Ruby interface to Ncrack, Network authentication cracking tool.")
    print("requires : nmap >= 0.3ALPHA / rprogram ~> 0.3")
    print("1 to accept / 0 to decline")
    choicencrack = raw_input("y / n :")
    if choicencrack in yes:
        os.system("git clone https://github.com/sophsec/ruby-ncrack.git");os.system("cd ruby-ncrack");os.systemgem("install ruby-ncrack")
    elif choicencrack in no:
        os.system("clear"); passwd()
#reaver
def reaver():
    print("Reaver has been designed to be a robust and practical attack against Wi-Fi Protected Setup")
    print(" WPS registrar PINs in order to recover WPA/WPA2 passphrases. It has been tested against a")
    print(") wide variety of access points and WPS implementations")
    print("1 to accept / 0 to decline")
    creaver = input("y / n :")
    if creaver in yes:
        os.system("apt-get -y install build-essential libpcap-dev sqlite3 libsqlite3-dev aircrack-ng pixiewps");os.system("git clone https://github.com/t6x/reaver-wps-fork-t6x.git");os.system("cd reaver-wps-fork-t6x");os.system("cd src/");os.system("./configure");os.system("make")
    elif creaver in no:
        os.system("clear"); wire()

#####################################
#information gathering function
def info():
    print("1 : nmap ")
    print("3 : SET tool kit")
    print("99 :Go Back To Main Menu")
    choice2 = input("selet a number :")
    choice2 = int(choice2)
    if choice2 ==1:
        os.system('clear'); nmap()
    if choice2 ==3:
        os.system("clear"); setoolkit()

    elif choice2 ==99:
        os.system("clear"); menu()
#end of menu 
##########################
#password attacks menu 
def passwd():
    print("1 : cupp ")
    print("2 : Ncrack")
    print("99:Back To Main Menu")
    choice3 = input("selet a number :")
    choice3 = int(choice3)
    if choice3 ==1:
     os.system("clear"); cupp()
    elif choice3 ==2:
        os.system("clear"); ncrack()
    elif choice3 ==99:
        os.system("clear"); menu()
#end of menu 
##########################
#wireless attacks
def wire():
    print("1 : reaver ")
    print("99: Go Back To The Main Menu")
    choice4 = input("selet a number :")
    choice4 = int(choice4)
    if choice4 ==1:
     os.system("clear");reaver()
    elif choice4 ==99:
        menu()
##########################
#exploitation tools
def exp():
    print("1 : jboss-autopwn ")
    print("2 : sqlmap")
    print("99 : Go Back To Main Menu")
    choice5 = input("selet a number :")
    choice5 = int(choice5)
    if choice5 ==2:
        os.system("clear"); sqlmap()
    if choice5 ==1:
     os.system('clear'); jboss()
    elif choice5 ==99:
        menu()
###########################
#sniffing tools
def snif():
    print("1 : Set Tool kit ")
    print("99: Back To Main Menu")
    choice6 = input("selet a number :")
    choice6 = int(choice6)
    if choice6 ==1:
     os.system("clear"); setoolkit()
    if choice6 ==99:
       os.system("clear"); menu()
#end of menu 
##########################
  #Check use OS
def OS():
    print(
    """
    Choose Operating System : 
    1) Max OSX
    2) Linux
    3) Windows
    """)
    system = input(":")
    system = str(system)
    if system ==2:
        root()
    else :
        menu()

############################
#check root if linux 
def root():
    if os.getuid() != 0:
        print("Are you root? Please execute as root")
        exit() 
#############################
#begin :D 
OS()
    
    
    
    
  
