from rich.console import Console
from rich.table import Table

import subprocess
import os

def handle_mysql_command(command: str, console: Console):
    os.system("clear")
    
    match command:
        case "0":
            console.print("Checking the mysql status ...", style="bold blue")
            
            subprocess.run("sudo systemctl status mysql", shell=True)
        
            console.print("Press any key to continue ...", style="bold blue")
        case "1":
            console.print("Starting the mysql server ...", style="bold blue")
            
            subprocess.run("sudo systemctl start mysql", shell=True)
            
            console.print("Press any key to continue ...", style="bold blue")
        case "2":
            console.print("Stopping the mysql server ...", style="bold blue")
            
            subprocess.run("sudo systemctl stop mysql", shell=True)
            
            console.print("Press any key to continue ...", style="bold blue")
        case "3":
            console.print("Restarting the mysql server ...", style="bold blue")
            
            subprocess.run("sudo systemctl restart mysql", shell=True)
            
            console.print("Press any key to continue ...", style="bold blue")
        case "4":
            console.print("Enabling the mysql server ...", style="bold blue")
            
            subprocess.run("sudo systemctl enable mysql", shell=True)
            
            console.print("Press any key to continue ...", style="bold blue")
        case "5":
            console.print("Disabling the mysql server ...", style="bold blue")
            
            subprocess.run("sudo systemctl disable mysql", shell=True)
            
            console.print("Press any key to continue ...", style="bold blue")
        case "6":
            console.print("Reloading the mysql server ...", style="bold blue")
            
            subprocess.run("sudo systemctl reload mysql", shell=True)
            
            console.print("Press any key to continue ...", style="bold blue")
        case "a":
            console.print("Logging into mysql server, type your root user credentials ...", style="bold blue")
            console.print("Type 'EXIT' to exit from mysql.", style="bold blue")
            
            subprocess.run("sudo mysql -u root -p", shell=True)
            
            console.print("Press any key to continue ...", style="bold blue")
        case _:
            console.print(f"Invalid command ID '{command}' !", style="bold red")
            console.print("Press any key to continue ...", style="bold blue")
            
    input()
    

def menu(console: Console):
    __table = Table(show_header=True, header_style="bold magenta")
    
    __table.title = "FST UbuntuMYSQL Utility"
    __table.add_column("Command ID", style="dim", width=12)
    __table.add_column("Command", style="dim", width=40)
    __table.add_column("Description", style="dim", width=60)
    
    
    __table.add_row("0", "sudo systemctl status mysql", "Check the mysql status")
    __table.add_row("1", "sudo systemctl start mysql", "start the mysql server")
    __table.add_row("2", "sudo systemctl stop mysql", "stop the mysql server")
    __table.add_row("3", "sudo systemctl restart mysql", "restart the mysql server")
    __table.add_row("4", "sudo systemctl enable mysql", "enable the mysql server")
    __table.add_row("5", "sudo systemctl disable mysql", "disable the mysql server")
    __table.add_row("6", "sudo systemctl reload mysql", "reload the mysql server")
    __table.add_section()
    __table.add_row("a", "mysql -u root -p", "login to mysql server as root user")
    
    
    console.print(__table, justify="center")

def main():
    os.system("clear")
    
    __console = Console()
    
    while True:
        os.system("clear")
        menu(__console)
        
        __choice = __console.input("Enter the command ID to execute or -1 to exit: ").strip()
        
        match __choice:
            case "-1":
                os.system("clear")
                __console.print("Are you sure, you want to exit ? [y/n]", style="bold red")
                _choice = input().strip().lower()
                
                match _choice:
                    case "y":
                        exit(0)
                    case _:
                        continue 
            case _:
                handle_mysql_command(__choice, __console)

if __name__ == "__main__":
    if os.name != "posix":
        raise Exception(f"'{os.name}' OS not supported !")
    
    try:
        main()
    except KeyboardInterrupt:
        os.system("clear")
        
        Console().print("Are you sure, you want to exit ? [y/n]", style="bold red")
        
        __choice = input().strip().lower()
        
        if __choice == "y": exit(0)
        else: main()