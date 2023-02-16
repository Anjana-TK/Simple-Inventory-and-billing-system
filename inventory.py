"""INVENTORY AND BILLING SYSTEM"""
class Inventory:
    c=0
    n=0
    serial={}
    def setval(self,name,rate,qty):
        Inventory.c+=1
        self.serial[Inventory.c]=[name,rate,qty]
        Inventory.n+=1
    def Display(self):
        if(Inventory.n==0):
            print("Sorry the Inventory is empty.")
            print("you can add products to the Inventory.")
        else:
            print("-----------------------------------------------")
            print("-----------------------------------------------")
            print("INVENTORY")
            print("-----------------------------------------------")
            print("-----------------------------------------------")
            print("SNo.\tName\tRate\tQuantity")
            print("-----------------------------------------------")
            for i in range(0,Inventory.n):
                print((i+1),"\t",self.serial[i+1][0],"\t",self.serial[i+1][1],"\t",self.serial[i+1][2],"\t",sep="")
class Bill(Inventory):
    m=0
    g=0
    purch={}
    total_p=0.0
    def setint(self,name,rate,qty):
        self.setval(name,rate,qty)
    def setBill(self,nm,q):
        x=-1
        for i in range(0,Inventory.n):
            if(self.serial[i+1][0]==nm):
                x=i+1
                break
        if x!=-1:
            if self.serial[x][2]>=q:
                Bill.g+=1
                self.purch[Bill.g]=[nm,self.serial[x][1],q,self.serial[x][1]*q]
                self.serial[x][2]-=q
                Bill.m+=1
            elif(self.serial[x][2]==0):
                print("Sorry the product is out of stock.")
            else:
                while(self.serial[x][2]<q):
                    print("Qty available for",Inventory.n,"is:",self.serial[x][2])
                    q=int(input("Enter the qty again:"))
                Bill.g+=1
                self.purch[Bill.g]=[nm,self.serial[x][1],q,self.serial[x][1]*q]
                self.serial[x][2]-=q
                Bill.m+=1
        else:
            print("Sorry the product doesn't exist.")
            ans=int(input("Do you wish to see the Inventory? (1 for yes and 0 for no):"))
            if(ans==1):
                self.Display()
    def disp(self):
        if(Bill.m==0):
            print("Sorry your cart is empty.")
            print("You can buy products that will be added to your cart.")
        else:
            print("-----------------------------------------------")
            print("-----------------------------------------------")
            print("BILL")
            print("-----------------------------------------------")
            print("-----------------------------------------------")
            print("SNo.\tName\tRate\tQuantity\tPrice")
            print("-----------------------------------------------")
            for i in range(0,Bill.m):
                print((i+1),"\t",self.purch[i+1][0],"\t",self.purch[i+1][1],"\t",self.purch[i+1][2],"\t",self.purch[i+1][3],"\t",sep="")
                self.total_p+=self.purch[i+1][3]
    def generatebill(self):
        self.disp()
        print("Total Price: Rs.",self.total_p)
        print("Thank you for vsiting us!")
        print("Please visit us again. :)")
print("-----------------------------------------------")
print("-----------------------------------------------")
print("WELOME TO THE DIGI MART")
print("-----------------------------------------------")
print("-----------------------------------------------")
b=Bill()
while(True):
    print("1. Add to Inventory\n2.Display Inventory\n3.Buy product\n4.Generate Bill")
    choice=int(input("Enter your choice(1-4):"))
    if(choice==1):
        while(True):
            sname=input("Enter the name of the product:")
            srate=float(input("Enter the rate of the product:"))
            sqty=int(input("Enter the quantity of the product: "))
            b.setint(sname,srate,sqty)
            p=int(input("Do you want to add more? ( 1 for yes and 0 for no):"))
            if(p==0):
                break
            else:
                continue
    elif(choice==2):
        b.Display()
    elif(choice==3):
        while(True):
            sname=input("Enter the name of the product:")
            sqty=int(input("Enter the quantity of the product: "))
            b.setBill(sname,sqty)
            p=int(input("Do you want to add more? ( 1 for yes and 0 for no):"))
            if(p==0):
                break
            else:
                continue
    elif(choice==4):
        b.generatebill()
        break
    else:
        print("Sorry option not found....Try again!")
