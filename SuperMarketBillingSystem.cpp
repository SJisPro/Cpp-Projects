#include<bits/stdc++.h>
using namespace std;
class Shopping {
  private:
    int pcode;
    float price;
    float dis;
    string pname;

    public:
      void menu();
      void administrator();
      void buyer();
      void add();
      void edit();
      void rem();
      void list();
      void receipt();
};

void Shopping :: menu() {
  m:
  int choice;
  string email;
  string password;

  cout<<"\t\t\t\t______________________________\n";
  cout<<"\t\t\t\t                              \n";
  cout<<"\t\t\t\t    SUPER MARKET MAIN MENU    \n";
  cout<<"\t\t\t\t______________________________\n"; 
  cout<<"\n\t\t\t\t                              \n";
  cout<<"\t\t\t\t|  1) Administrator  |\n";
  cout<<"\t\t\t\t|                    |\n";
  cout<<"\t\t\t\t|  2) Buyer          |\n";
  cout<<"\t\t\t\t|                    |\n";
  cout<<"\t\t\t\t|  3) Exit           |\n\n";
  cout<<"\n\t Please enter your choice: ";
  cin>>choice;
  switch(choice) {
    case 1:
      cout<<"\n\t Please Login \n";
      cout<<"\n\t Enter Username:   ";
      cin>>email;
      cout<<"\n\t Enter Password:   ";
      cin>>password;
      if(email=="admin" && password=="admin") {
        administrator();
        break;
      } else {
        cout<<"\t\t\t Invalid Email or Password \n";
      }
      break;
    case 2:
      buyer();
      break;
    case 3:
      cout<<"\n\nThanks for Shopping. Please Visit Again.\n\n";
      exit(0);
      break;
    default:
      cout<<"Please Select from the Given Options"<<endl;
  }
  goto m;
}

void Shopping :: administrator() {
  m:
  int choice;
  cout<<"\n\n\n\t\t\t\t ADMINISTRATOR MENU";
  cout<<"\n\t\t\t\t|_____1) Add the product_____|";
  cout<<"\n\t\t\t\t|                            |";
  cout<<"\n\t\t\t\t|_____2) Modify the product__|";
  cout<<"\n\t\t\t\t|                            |";
  cout<<"\n\t\t\t\t|_____3) Delete the product__|";
  cout<<"\n\t\t\t\t|                            |";
  cout<<"\n\t\t\t\t|_____4) Back to main menu____|";

  cout<<"\n\n\t Please enter your choice: ";
  cin>>choice;

  switch(choice) {
    case 1:
      add();
      break;
    case 2:
      edit();
      break;
    case 3:
      rem();
      break;
    case 4:
      menu();
      break;
    default:
      cout<<"Please Select from the Given Options"<<endl;
  }
  goto m;
}

void Shopping :: buyer() {
  m:
  int choice;
  cout<<"\n\n\t\t\t  BUYER \n";
  cout<<"\t\t\t________________\n";
  cout<<"\t\t\t 1) Buy Product \n";
  cout<<"                      \n";
  cout<<"\t\t\t 2) Go Back     \n";
  cout<<"\n\t\t\t Enter your choice: ";
  cin>>choice;
  switch(choice) {
    case 1:
      receipt();
      break;
    case 2:
      menu();
      break;
    default:
      cout<<"Please Select from the Given Options"<<endl;
  }
  goto m;
}

void Shopping :: add() {
  m:
  fstream data;
  int c;
  int token = 0;
  float p;
  float d;
  string n;

  cout<<"\n\n\t\t\t Add New Product";
  cout<<"\n\n\t Product Code: ";
  cin>>pcode;
  cout<<"\n\t Product Name: ";
  cin>>pname;
  cout<<"\n\t Product Price: ";
  cin>>price;
  cout<<"\n\t Discount: ";
  cin>>dis;

  data.open("product.txt", ios::in);
  if(!data) {
    data.open("product.txt", ios::app|ios::out);
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
    data.close();
  }
  else {
    data>>c>>n>>p>>d;

    while(!data.eof()) {
      if(c==pcode) {
        token++;
      }
      data>>c>>n>>p>>d;
    }
    data.close();
    if(token==1) {
      cout<<"\n\n\t Product Code Already Exists. Please try again!";
      goto m;
    }
    else {
      data.open("product.txt", ios::app|ios::out);
      data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
      data.close();
    }
  }
  cout<<"\n\n\t\t Product Added Successfully";
}

void Shopping :: edit() {
  fstream data, data1;
  int pkey;
  int token=0;
  int c;
  float p;
  float d;
  string n;
  cout<<"\n\t\t\t Modify Product";
  cout<<"\n\n\t\t\t Enter Product Code: ";
  cin>>pkey;
  data.open("product.txt", ios::in);
  if(!data) {
    cout<<"\n\n File Doesn't Exist";
  }
  else {
    data1.open("product1.txt", ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()) {
      if(pkey==pcode) {
        cout<<"\n\t Product New Code: ";
        cin>>c;
        cout<<"\n\t Product New Name: ";
        cin>>n;
        cout<<"\n\t Product New Price: ";
        cin>>p;
        cout<<"\n\t Product New Discount: ";
        cin>>d;
        data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
        cout<<"\n\n\t\t Product Modified Successfully";
        token++;
      }
      else {
        data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
      }
      data>>pcode>>pname>>price>>dis;
    }
    data.close();
    data1.close();
    remove("product.txt");
    rename("product1.txt", "product.txt");
    if(token==0) {
      cout<<"\n\n\t\t Product Not Found";
    }
  }
}

void Shopping :: rem() {
  fstream data, data1;
  int pkey;
  int token = 0;
  cout<<"\n\n\t Delete Product";
  cout<<"\n\n\t Enter Product Code: ";
  cin>>pkey;
  data.open("product.txt", ios::in);
  if(!data) {
    cout<<"\n\n File Doesn't Exist";
  }
  else {
    data1.open("product1.txt", ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()) {
      if(pkey==pcode) {
        cout<<"\n\n\t Product Deleted Successfully";
        token++;
      }
      else {
        data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
      }
      data>>pcode>>pname>>price>>dis;
    }
    data.close();
    data1.close();
    remove("product.txt");
    rename("product1.txt", "product.txt");

    if(token==0) {
      cout<<"\n\n\t Product Not Found";
    }
  }
}

void Shopping :: list() {
  fstream data;
  data.open("product.txt", ios::in);
  cout<<"\n|______________________________________________\n";
  cout<<"  Product No\tProduct Name\tPrice\n\n";
  data>>pcode>>pname>>price>>dis;
  while(!data.eof()) {
    cout<<"  "<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
    data>>pcode>>pname>>price>>dis;
  }
  data.close();
}

void Shopping :: receipt() {
  fstream data;
  int a;
  int b;
  int arrc[100];
  int arrq[100];
  char choice;
  int c = 0;
  float amount = 0;
  float dis = 0;
  float total = 0;
  cout<<"\n\n\t\t RECEIPT";
  data.open("product.txt", ios::in);
  if(!data) {
    cout<<"\n\n File Doesn't Exist";
  }
  else {
    data.close();
    list();
    cout<<"\n_____________________________________\n";
    cout<<"|                                   |\n";
    cout<<"|        Please Place the Order     |\n";
    cout<<"|                                   |\n";
    cout<<"_____________________________________\n";
    do {
      m:
      cout<<"\n\n\t Enter Product Code: ";
      cin>>a;
      bool found = false;
      data.open("product.txt", ios::in);
      while (data >> pcode >> pname >> price >> dis) {
        if (pcode == a) {
            found = true;
            break; // Exit the loop as the product code is found
        }
      }
      data.close();
      if (!found) {
        cout << "\n\n Product Code Not Found. Please try again!";
        goto m;
      }
      else {
        cout<<"\n\t Enter Quantity: ";
        cin>>b;
        arrc[c] = a;
        arrq[c] = b;    
        for(int i=0;i<c;i++) {
          if(arrc[c]==arrc[i]) {
            cout<<"\n\n Duplicate Product Code. Please try again!";
            goto m;
          }
        }  
        c++;
        cout<<"\n\n\t Do you want to buy another product? (y/n): ";
        cin>>choice;
      }
    } while(choice=='y' || choice=='Y');

    cout<<"\n\n\t\t\t_____________RECEIPT______________\n";
    cout<<"\nProduct No\tProduct Name\t Quantity    Price    Amount\t Amount after Discount\n";

   for(int i=0;i<c;i++) {
    data.open("product.txt", ios::in);
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()) {
      if(pcode == arrc[i]) {
        amount = price*arrq[i];
        dis = amount - (amount*dis/100);
        total = total + dis;
        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t "<<arrq[i]<<"\t     "<<price<<"\t      "<<amount<<"\t "<<dis;
      }
      data>>pcode>>pname>>price>>dis;
    }
    data.close(); 
   }
  }
  cout<<"\n\n___________________________________________";
  cout<<"\n Total Amount: "<<total<<endl;
}

int main() {
  Shopping s;
  s.menu();
  return 0;
}