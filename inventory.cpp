//INVENTORY AND BILLING SYSTEM
#include<iostream>
using namespace std;
class Inventory{
    public:
        static int c;
        static int n;
        string name[100];
        double rate[100];
        int serial[100];
        int qty[100];
        void setval(string name,double rate, int qty){
            this.name[n]=name;
            this.rate[n]=rate;
            this.qty[n]=qty;
            c();
            this.serial[n]=c;
            setn();
        }
        static void setn(){
            n+=1;
        }
        static void c(){
            c+=1;
        }
        void Display(){
            if(n==0){
                cout<<"Sorry the Inventory is empty."<<endl;
                cout<<"You can add products to the Inventory."<<endl;
            }
            else{
                cout<<"-----------------------------------------------"<<endl;
                cout<<"-----------------------------------------------"<<endl;
                cout<<"INVENTORY"<<endl;
                cout<<"-----------------------------------------------"<<endl;
                cout<<"-----------------------------------------------"<<endl;
                cout<<"Serial No.\tName\tRate\tQuantity"<<endl;
                cout<<"-----------------------------------------------"<<endl;
                for(int i=0;i<n;i++){
                    cout<<serial[i]+"\t\t"+name[i]+"\t"+rate[i]+"\t"+qty[i]<<endl;
                }
            }
        }
}
int Inventory::s=0;
int Inventory::c=0;
class Bill : public Inventory{
    public:
        static int m=0;
        static int g=0;
    private:
        char purch_name[100][50];
        double purch_rate[100];
        int purch_qty[100];
        double purch_price[100];
        int purch_serial[100];
        double total_price=0.0;
    public:
        void setint(string name,double rate,int qty){
            setval(name,rate,qty);
        }
        void setBill(int nm,int q){
            int x=-1;
            for(int i=0;i<Inventory.n;i++){
                if(name[i]==nm){
                    x=i;
                    break;
                }
            }
            if(x!=-1){
                if(qty[x]>=q){
                    purch_name[m]=name[x];
                    purch_rate[m]=rate[x];
                    purch_qty[m]=q;
                    qty[x]-=q;
                    purch_price[m]=q*purch_rate[m];
                    g();
                    purch_serial[m]=g;
                    m();
                }
                else if(qty[x]==0){
                    cout<<"Sorry the product is out of stock."<<endl;
                }
                else{
                    while(qty[x]<q){
                        cout<<"Qty available for "<<n<<" is: "<<qty[x]<<endl;
                        cout<<"Enter the qty again:";
                        cin>>q;
                    }
                    purch_name[m]=name[x];
                    purch_rate[m]=rate[x];
                    purch_qty[m]=q;
                    qty[x]-=q;
                    purch_price[m]=q*purch_rate[m];
                    g();
                    purch_serial[m]=g;
                    m();
                }
            }
            else{
                cout<<"Sorry the product doesn't exist."<<endl;
                cout<<"Do you wish to see the Inventory? (1 for yes and 0 for no):";
                int ans;
                cin>>ans;
                if(ans==1){
                    Display();
                }
            }
        }
        static void g(){
            g+=1;
        }
        void disp(){
            if(m==0){
                cout<<"Sorry your cart is empty."<<endl;
                cout<<"You can buy products that will be added to your cart."<<endl;
            }
            else{
                cout<<"-----------------------------------------------"<<endl;
                cout<<"-----------------------------------------------"<<endl;
                cout<<"BILL"<<endl;
                cout<<"-----------------------------------------------"<<endl;
                cout<<"-----------------------------------------------"<<endl;
                cout<<"Serial No.\tName\tRate\tQuantity\tPrice"<<endl;
                cout<<"-----------------------------------------------"<<endl;
                for(int i=0;i<m;i++){
                    cout<<purch_serial[i]<<"\t\t"<<purch_name[i]<<"\t"<<purch_rate[i]<<"\t"<<purch_qty[i]<<"\t\t"<<purch_price[i]<<endl;
                    total_price+=purch_price[i];
                }
            }
        }
        void generatebill(){
            disp();
            cout<<"Total Price: Rs."<<total_price<<endl;
            cout<<"Thank you for vsiting us!"<<endl;
            cout<<"Please visit us again. :)"<<endl;
        }
        static void m(){
            m+=1;
        }
}
cout<<"-----------------------------------------------"<<endl;
cout<<"-----------------------------------------------"<<endl;
cout<<"WELOME TO THE DIGI MART"<<endl;
cout<<"-----------------------------------------------"<<endl;
cout<<"-----------------------------------------------"<<endl;
int choice,p;
string sname;
double srate;
int sqty;
Bill b;
while(true){
    cout<<"1. Add to Inventory\n2.Display Inventory\n3.Buy product\n4.Generate Bill\nEnter your choice(1-4):";
    cin>>choice;
    if(choice==1){
        while(true){
            cout<<"Enter the name of the product:";
            cin>>sname;
            cout<<"Enter the rate of the product:";
            cin>>srate;
            cout<<"Enter the quantity of the product:";
            cin>>sqty;
            b.setint(sname,srate,sqty);
            cout<<"Do you want to add more? ( 1 for yes and 0 for no):";
            cin>>p;
            if(p==0){
                break;
            }
            else{
                continue;
            }
        }
    }
    else if(choice==2){
        b.Display();
    }
    else if(choice==3){
        while(true){
            cout<<"Enter the name of the product:";
            cin>>sname;
            cout<<"Enter the quantity of the product:";
            cin>>sqty;
            b.setBill(sname,qty);
            cout<<"Do you want to buy more? ( 1 for yes and 0 for no):";
            cin>>p;
            if(p==0){
                break;
            }
            else{
                continue;
            }
        }
    }
    else if(choice==4){
        b.generatebill();
        break;
    }
    else{
        cout<<"Sorry option not found....Try again!"<<endl;
    }
}
