#include<iostream>
#include<string>
#include<string.h>
using namespace std;
long int ac=10000000;
int opz;
int c=0;
int k;
int i=0;
int opt;
int att=3;
long int num;
float amount;
class per_inf/*1*/
{
protected:
    string name;
    string mob_no;
    string DOB;
    string email_id;
    string aadhar_num;
    string add;
public:
    void get_data_per_inf(void);
    void display_per_inf(void);
    void display_name(void);
    void upd_per_inf(int a);
    int check_adhar(string a);
    int check_mob_no(string a);


};
void per_inf::get_data_per_inf(void)
{
    cout<<"Please fill the given personal information : "<<endl;
    cout<<"NAME : ";
    cin>>name;
    cout<<"MOBILE NUMBER : ";
    cin>>mob_no;
    cout<<"DATE OF BIRTH : ";
    cin>>DOB;
    cout<<"EMAIL-ID : ";
    cin>>email_id;
    cout<<"AADHAR NUMBER : ";
    cin>>aadhar_num;
    cout<<"ADDRESS : ";
    cin>>add;
    system("CLS");

}
void per_inf::display_per_inf(void)
{
    cout<<"PERSONAL INFORMATION : "<<endl;
    cout<<"NAME: "<<name<<endl;
    cout<<"MOBILE NUMBER: "<<mob_no<<endl;
    cout<<"EMAIL-ID: "<<email_id<<endl;
    cout<<"DOB: "<<DOB<<endl;
    cout<<"AADHAR NUMBER: "<<aadhar_num<<endl;
    cout<<"ADDRESS: "<<add<<endl;

}
int per_inf::check_mob_no(string a)
{
    if(!mob_no.compare(a))
        return 1;
    else
        return 0;
}
int per_inf::check_adhar(string a)
{
    if(!aadhar_num.compare(a))
        return 1;
    else
        return 0;
}
void per_inf::upd_per_inf(int a)
{
    switch(a)
    {
    case 1:
        {
            cout<<"ENTER NEW NAME: ";
            cin>>name;
            break;
        }
        case 2:
        {
            cout<<"ENTER NEW MOBILE NUMBER: ";
            cin>>mob_no;
            break;
        }
        case 3:
        {
            cout<<"ENTER NEW DATE OF BIRTH(FORMAT SHOULD BE DD-MM-YYYY): ";
            cin>>DOB;
            break;
        }
        case 4:
        {
            cout<<"ENTER NEW EMAIL-ID: ";
            cin>>email_id;
            break;
        }
        case 5:
        {
            cout<<"ENTER NEW ADDRESS: ";
            cin>>add;
            break;
        }
    }
}
void per_inf::display_name(void)
{
    cout<<name;
}
class bank_det/*2*/
{
    protected:
    string branch;
    string IFSC_code;
public:
    void get_data_bank_det(void);
    void display_bank_det(void);

};
void bank_det::get_data_bank_det(void)
{
    cout<<"Please enter the following bank detail: "<<endl;
    cout<<"BRANCH-NAME: ";
    cin>>branch;
    cout<<"IFSC-CODE: ";
    cin>>IFSC_code;
    system("CLS");
}
void bank_det::display_bank_det(void)
{
    cout<<"BANK DETAILS : "<<endl;
    cout<<"BRANCH NAME : "<<branch<<endl;
    cout<<"IFSC-CODE : "<<IFSC_code<<endl;
}

class onli_bank/*3*/
{
    protected:
    string username;
    string password;
    public:
        void get_data_onli_bank(void);
        int check_username(string a);
        int check_pass(string a);
        void change_pass(string a);
        void display_user(void)
        {
            cout<<username<<endl;
        }

};
void onli_bank::get_data_onli_bank(void)
{
    string pass1,pass2;
    label:
    cout<<"Fill the following details to create net banking account : "<<endl;
    cout<<"User-name: ";
    cin>>username;
    cout<<"PASSWORD: ";
    cin>>pass1;
    cout<<"CONFIRM PASSWORD: ";
    cin>>pass2;
    while(pass1!=pass2)
    {
        cout<<"Wrong password entered!!!"<<endl;
        cout<<"Confirm your password again :";
        cin>>pass2;
    }
    password=pass1;
    cout<<"YOUR NET-BANKING ACCOUNT IS SUCCESSFULLY CREATED!!!"<<endl;
system("CLS");
}
void onli_bank::change_pass(string a)
{
    password=a;
}
int onli_bank::check_username(string a)
{
    if(!a.compare(username))
        return 1;
    else
        return 0;
}
int onli_bank::check_pass(string a)
{
    if(!a.compare(password))
        return 1;
    else
        return 0;
}

class Bank:public per_inf,public bank_det,public onli_bank/*main class*/
{

float bal;
long int upi;
 long int acc_no;
static int otp;
public:
    static int generate_otp(void)
    {
        otp+=13;
        return otp;
    }

    int check_identity(string a);
    void get_upi(void);
    void display_bal(void);
    int check_upi(long int a);
    void add_bal(float a);
    int sub_bal(float a);
    void set_acc_no(long int a)
    {
        acc_no=a;

    }
    long int give_acc_no(void)
    {
        return acc_no;
    }

void display_acc_no(void)
{
    cout<<"BANK ACCOUNT NUMBER: "<<acc_no<<endl;
}


};

int Bank::otp=1001;
int Bank::sub_bal(float a)
{
    if(bal>=a)
    {bal-=a;
    return 1;}
    else
    {
        cout<<"INSUFFICIENT BALANCE!!!"<<endl;
        return 0;

    }
}
void Bank::add_bal(float a)
{
    bal+=a;
}
int Bank::check_upi(long int a)
{
    if(upi==a)
        return 1;
    else
        return 0;
}
void Bank::get_upi(void)
{
    cout<<"SET YOUR UPI: "<<endl;
    cout<<"ENTER THE 6-DIGIT UPI NUMBER:";
    int a,b;
    cin>>a;
    cout<<"CONFIRM YOUR UPI:";
    cin>>b;
     while(a!=b)
    {
        cout<<"WRONG UPI ENTERED!!!"<<endl;
        cout<<"ENTER THE CORRECT UPI:";
        cin>>b;

    }
    upi=a;

}
void Bank::display_bal(void)
{
    cout<<"AVAILABLE BALANCE: Rs."<<bal<<endl;
}
int Bank::check_identity(string a)
{
    if(!DOB.compare(a))
        return 1;
    else
        return 0;
}

Bank B[10];
int main()
{


    cout<<"HI,Welcome to our bank..."<<endl;
    mainmenu:
    cout<<"Please select the appropriate option corresponding to the task to be performed:"<<endl;
    cout<<" 1.CREATE NEW ACCOUNT"<<endl;
    cout<<" 2.LOGIN"<<endl;
    cout<<" 3.EXIT"<<endl;
    cout<<"Enter the appropriate option:";
    cin>>opt;
    switch(opt)
    {
    case 1:
        {
            new_acc:
            B[i].get_data_per_inf();
            B[i].get_data_bank_det();
            B[i].set_acc_no(ac);
            ac++;
            B[i].get_upi();
            cout<<"YOUR UPI IS SET SUCCESSFULLY!!!"<<endl;
            system("CLS");
            B[i].get_data_onli_bank();
            cout<<"Your BANK ACCOUNT is: "<<endl;
            B[i].display_acc_no();
            i++;
            cout<<"THANK YOU FOR CREATING ACCOUNT IN OUR BANK : "<<endl;
            cout<<"Enter '1' to Create another new account and Enter '0' to return to main menu: ";

                            cin>>opz;
                            if(opz==1)
                                {
                                    system("CLS");
                                    goto new_acc;
                                }
                                else
                                    {
                                        system("CLS");
                                        goto mainmenu;
                                    }
            break;

        }
    case 2:
        {
            use_name:
                string user_nam,pass;
            cout<<"Please enter your username and password : "<<endl;
            cout<<"USERNAME :";
            cin>>user_nam;
            for(k=0;k<i;k++)
            {

               if(B[k].check_username(user_nam))
               {
                   c++;
                   break;
               }
            }
            if(c==0)
                {
                    cout<<"Enter valid username :"<<endl;
                    cout<<"Enter '1' to TRY AGAIN and Enter '0' to RETURN TO MAIN MENU: ";

                            cin>>opz;
                            if(opz==1)
                                {
                                    system("CLS");
                                    goto use_name;
                                }
                                else
                                { system("CLS");
                                    goto mainmenu;}

                }

            else
            {
                sec:
                cout<<"PASSWORD: ";
                cin>>pass;
                if(B[k].check_pass(pass))
                {
                    MM:
                        system("CLS");
                    cout<<"Please select the appropriate option :"<<endl;
                    cout<<"WELCOME ";
                    B[k].display_name();
                    cout<<endl;
                    cout<<"1.CHECK BANK BALANCE"<<endl;
                    cout<<"2.DEPOSIT MONEY"<<endl;
                    cout<<"3.WITHDRAW MONEY"<<endl;
                    cout<<"4.TRANSFER MONEY"<<endl;
                    cout<<"5.UPDATE PEESONAL INFORMATION"<<endl;
                    cout<<"6.CHANGE UPI PIN"<<endl;
                    cout<<"7.LOG OUT"<<endl;
                    cout<<"Enter the appropriate option: ";
                    cin>>opt;
                    switch(opt)
                    {
                case 1:
                    {


                        cout<<"ENTER 6-DIGIT UPI:";
                        cin>>num;
                        system("CLS");
                        if(B[k].check_upi(num))
                            B[k].display_bal();
                        else
                        {
                            cout<<"YOU HAVE ENTERED WRONG UPI!!!"<<endl;
                            cout<<"TRY AGAIN.YOU HAVE 3 ATTEMPTS LEFT."<<endl;
                            system("CLS");
                            att=3;
                            do
                            {
                                cout<<"ENTER 6-DIGIT UPI:";
                                cin>>num;
                                system("CLS");
                                if(B[k].check_upi(num))
                            {
                                B[k].display_bal();
                                break;
                            }
                            else
                                cout<<att-1<<" ATTEMPT LEFT!!!"<<endl;
                                system("CLS");
                            att--;

                            }while(att>0);
                           if(att==0)
                           {
                                cout<<"TOO MANY UNSUCCESSFUL ATTEMPTS.TRY TO CHANGE PIN OR CONTACT YOUR BANK."<<endl;

                           }


                        }
                        cout<<"Enter '1' to return to Main Menu and Enter '0' to Exit: ";

                            cin>>opz;
                            if(opz==1)
                                {
                                    system("CLS");
                                    goto MM;
                                }
                                else
                                    {
                                        system("CLS");
                                        goto exit;
                                    }
                        break;
                    }
                case 2:
                    {
                        cout<<"Enter the amount to be deposited: ";
                        cin>>amount;
                        system("CLS");
                        cout<<"ENTER 6-DIGIT UPI:";
                        cin>>num;
                        system("CLS");
                        if(B[k].check_upi(num))
                           {
                               B[k].add_bal(amount);
                               B[k].display_bal();

                           }
                        else
                        {
                            cout<<"YOU HAVE ENTERED WRONG UPI!!!"<<endl;
                            cout<<"TRY AGAIN.YOU HAVE 3 ATTEMPTS LEFT."<<endl;
                            system("CLS");
                            att=3;
                            do
                            {
                                cout<<"ENTER 6-DIGIT UPI:";
                                cin>>num;

                                if(B[k].check_upi(num))
                            {
                                B[k].add_bal(amount);
                                B[k].display_bal();
                                system("CLS");
                                break;
                            }
                            else
                                cout<<"YOU HAVE ENTERED WRONG UPI!!!"<<endl;
                                cout<<att-1<<" ATTEMPT LEFT!!!"<<endl;
                                system("CLS");
                            att--;

                            }while(att>0);
                           if(att==0)
                           {
                                cout<<"TOO MANY UNSUCCESSFUL ATTEMPTS.TRY TO CHANGE PIN OR CONTACT YOUR BANK."<<endl;

                           }


                        }
                        cout<<"Enter '1' to return to Main Menu and Enter '0' to Exit: ";

                            cin>>opz;
                            if(opz==1)
                                {
                                    system("CLS");
                                    goto MM;
                                }
                                else
                                   {
                                       system("CLS");
                                       goto exit;
                                   }
                        break;
                    }
                case 3:
                    {
                        cout<<"Enter the amount to be withdrawn: ";
                        cin>>amount;
                        system("CLS");
                        cout<<"ENTER 6-DIGIT UPI:";
                        cin>>num;
                        system("CLS");
                        if(B[k].check_upi(num))
                           {
                               B[k].sub_bal(amount);
                               B[k].display_bal();

                           }
                        else
                        {
                            cout<<"YOU HAVE ENTERED WRONG UPI!!!"<<endl;
                            cout<<"TRY AGAIN.YOU HAVE 3 ATTEMPTS LEFT."<<endl;
                            system("CLS");
                            att=3;
                            do
                            {
                                cout<<"ENTER 6-DIGIT UPI:";
                                cin>>num;
                                if(B[k].check_upi(num))
                            {
                                B[k].sub_bal(amount);
                                B[k].display_bal();
                                break;
                            }
                            else
                                cout<<"YOU HAVE ENTERED WRONG UPI!!!"<<endl;
                                cout<<att-1<<" ATTEMPT LEFT!!!"<<endl;
                                system("CLS");
                            att--;

                            }while(att>0);
                           if(att==0)
                           {
                                cout<<"TOO MANY UNSUCCESSFUL ATTEMPTS.TRY TO CHANGE PIN OR CONTACT YOUR BANK."<<endl;

                           }


                        }
                        cout<<"Enter '1' to return to Main Menu and Enter '0' to Exit: ";

                            cin>>opz;
                            if(opz==1)
                                {
                                    system("CLS");
                                    goto MM;
                                }
                                else
                                    {
                                        system("CLS");
                                        goto exit;
                                        }
                        break;
                    }
                case 4:
                    {
                        long int tra_acc;
                        cout<<"ENTER THE ACCOUNT NUMBER TO WHICH MONEY HAS TO BE TRANSFERRED:";
                        cin>>tra_acc;
                        system("CLS");
                        int z;
                        for( z=0;z<10;z++)
                        {
                            if(tra_acc==B[z].give_acc_no())
                                break;

                        }
                        if(z==10)
                        {
                            cout<<"BANK ACCOUNT IS NOT FOUND!!!"<<endl;

                        }
                        else
                        {
                            cout<<"ENTER THE AMOUNT TO BE TRANSFERRED: ";
                            cin>>amount;
                             system("CLS");
                            cout<<"ENTER 6-DIGIT UPI:";
                        cin>>num;
                        system("CLS");
                         if(B[k].check_upi(num))
                         {
                              B[z].add_bal(amount);
                            if(!B[k].sub_bal(amount))
                            {
                                cout<<"Enter '1' to return to Main Menu and Enter '0' to Exit: ";

                            cin>>opz;
                            if(opz==1)
                                {
                                    system("CLS");
                                    goto MM;
                                }
                                else
                                    {
                                        system("CLS");
                                        goto exit;}

                            }
                            B[k].display_bal();
                            system("CLS");

                         }
                         else
                        {
                            cout<<"YOU HAVE ENTERED WRONG UPI!!!"<<endl;
                            cout<<"TRY AGAIN.YOU HAVE 3 ATTEMPTS LEFT."<<endl;
                            system("CLS");
                            att=3;
                            do
                            {
                                cout<<"ENTER 6-DIGIT UPI:";
                                cin>>num;
                                if(B[k].check_upi(num))
                            {
                                B[k].sub_bal(amount);
                                B[k].display_bal();
                                break;
                            }
                            else
                                cout<<"YOU HAVE ENTERED WRONG UPI!!!"<<endl;
                                cout<<att-1<<" ATTEMPT LEFT!!!"<<endl;
                                system("CLS");
                            att--;

                            }while(att>0);
                           if(att==0)
                           {
                                cout<<"TOO MANY UNSUCCESSFUL ATTEMPTS.TRY TO CHANGE PIN OR CONTACT YOUR BANK."<<endl;

                           }


                        }




                        }
                        cout<<"Enter '1' to go to main menu or enter '0' to EXIT :";
                             cin>>opz;
                            if(opz==1)
                                {
                                    system("CLS");
                                    goto MM;
                                }
                                else
                                    {system("CLS");
                                        goto exit;
                                    }
                        break;
                    }
                case 5:
                    {
                        upd:
                        cout<<"Please select the appropriate option corresponding to what kind of personal information is to be updated."<<endl;
                        cout<<"1.NAME"<<endl;
                        cout<<"2.MOBILE NUMBER"<<endl;
                        cout<<"3.DATE OF BIRTH"<<endl;
                        cout<<"4.EMAIL-ID"<<endl;
                        cout<<"5.ADDRESS"<<endl;
                        cout<<"Enter the appropriate option:";
                        cin>>opt;
                        system("CLS");
                        B[k].upd_per_inf(opt);
                        cout<<"Enter '1' to return to Main Menu, Enter '2' to update other personal information and Enter '0' to Exit: ";
                        cin>>opz;
                            if(opz==1)
                                {
                                    system("CLS");
                                    goto MM;
                                }
                                else if(opz==2)
                                    {
                                        system("CLS");
                                        goto upd;
                                    }
                        else
                            {
                                system("CLS");
                                goto exit;
                            }
                        break;

                    }
                case 6:
                    {
                        string BOD;
                        cout<<"ENTER YOUR DATE OF BIRTH:(THE FORMAT SHOULD BE DD-MM-YYYY) ";
                        cin>>BOD;
                        system("CLS");
                        if(B[k].check_identity(BOD))//1
                        {
                            re_ad:
                        string ad_num;
                        cout<<"ENTER YOUR AADHAR NUMBER: ";
                        cin>>ad_num;
                        system("CLS");
                        if(B[k].check_adhar(ad_num))//2
                        {
                            re_mob:
                            string mob1,mob2;
                            cout<<"Enter your registered mobile number: ";
                            cin>>mob1;
                            cout<<"Confirm your mobile number: ";
                            cin>>mob2;
                            system("CLS");
                            while(mob1!=mob2)
                            {
                                cout<<"Mobile number is not matched with previous one!!!"<<endl;
                                cout<<"Confirm the mobile number again: ";
                                cin>>mob2;
                                system("CLS");
                            }
                            if(B[k].check_mob_no(mob1))//3
                            {
                                re_otp:
                                int otp1=B[k].generate_otp();
                                cout<<"OTP: "<<otp1<<endl;

                                int opt2;
                                cout<<"Enter OTP: ";
                                cin>>opt2;
                                system("CLS");
                                if(otp1==opt2)
                                {
                                    B[k].get_upi();
                                    cout<<"YOUR UPI IS CHANGED SUCESSFULLY!!!"<<endl;
                                    system("CLS");
                                }
                                else
                                {
                                    cout<<"Enter '1' to resend another OTP and enter '0' to return to main menu: ";
                                     cin>>opz;
                            if(opz==1)
                                {
                                    system("CLS");
                                    goto re_otp;
                                    }
                                else
                                    {
                                        system("CLS");
                                        goto MM;
                                    }
                                }
                            }
                            else//3
                            {
                               cout<<"ENTERED MOBILE NUMBER IS NOT REGISTERED.PLEASE ENTER REGISTERED MOBILE NUMBER."<<endl;

                            }

                        }
                        else//2
                        {
                            cout<<"AADHAR NUMBER IS NOT MATCH!!!"<<endl;

                        }

                        }
                        else
                        {
                            cout<<"YOU HAVE ENTERED WRONG DOB!!!"<<endl;
                            cout<<"TRY AGAIN.YOU HAVE 3 ATTEMPTS LEFT."<<endl;
                            att=3;
                            system("CLS");
                            do
                            {
                                 cout<<"ENTER YOUR DATE OF BIRTH:(THE FORMAT SHOULD BE DD-MM-YYYY) ";
                                 cin>>BOD;
                                 system("CLS");
                               if(B[k].check_identity(BOD))
                            {
                                goto re_ad;

                            }
                            else
                                cout<<att-1<<" ATTEMPT LEFT!!!"<<endl;
                                system("CLS");
                            att--;

                            }while(att>0);
                           if(att==0)
                           {
                                cout<<"TOO MANY UNSUCCESSFUL ATTEMPTS.TRY TO CONTACT BANK."<<endl;

                        }






                    }
                    cout<<"Enter '1' to return to Main Menu and Enter '0' to Exit: ";

                            cin>>opz;
                            if(opz==1)
                                {
                                    system("CLS");
                                    goto MM;
                                    }
                                else
                                    {
                                        system("CLS");
                                        goto exit;
                                        }
                    break;




                    }
                case 7:
                    {
                        cout<<"YOU ARE SUCCESSFULLY LOGGED OUT";
                        B[k].display_name();
                    cout<<"!!!"<<endl;
                        cout<<"Enter '1' to return to Main Menu and Enter '0' to Exit: ";

                            cin>>opz;
                            if(opz==1)
                                {
                                    system("CLS");
                                    goto mainmenu;
                                    }
                                else
                                    {
                                        system("CLS");
                                        goto exit;
                                        }
                    break;
                    }



                }
                }

                else//1
                {
                    cout<<"INVALID PASSWORD!!"<<endl;
                    cout<<"Please select the correct option: ";
                    cout<<"1.TRY AGAIN"<<endl;
                    cout<<"2.FORGET PASSWORD"<<endl;
                    cout<<"Enter appropriate number :";
                    int as;
                    cin>>as;
                    system("CLS");
                    if(as==1)//2
                    {

                    att=3;
                    while(att>0)
                    {
                        goto sec;
                        att--;
                    }
                    cout<<"TOO MANY UNSUCCESSSFUL ATTEMPTS! TRY AGAIN LATER!!";
                    cout<<"Enter '1' to return to main menu and enter '0' to Exit: ";
                    cin>>opz;
                    if(opz==1)
                    {
                        system("CLS");
                        goto mainmenu;
                    }
                    else
                    {
                        system("CLS");
                        goto exit;
                    }

                    }//2
                    else//3
                    {
                        abc:
                        cout<<"Enter your date of birth to confirm your identity (NOTE: The format should be DD-MM-YYYY) : ";
                        string dob;
                        cin>>dob;
                        system("CLS");
                        if(B[k].check_identity(dob))//4
                        {
                            xyz:
                            cout<<"ENTER NEW PASSWORD :";
                            string pswrd1,pswrd2;
                            cin>>pswrd1;
                            cout<<"CONFIRM YOUR PASSWORD AGAIN :";
                            cin>>pswrd2;
                            system("CLS");
                            if(!pswrd1.compare(pswrd2))//5
                            {
                                B[k].change_pass(pswrd1);
                                cout<<"PASSWORD IS CHANGED SUCCESSFULLY!!"<<endl;
                                system("CLS");
                                cout<<"Enter '1' to go to main menu or enter '0' to EXIT :";

                                cin>>opz;
                                if(opz==1)
                                    {
                                        system("CLS");
                                        goto mainmenu;}
                                else
                                    {
                                        system("CLS");
                                        goto exit;}
                            }//5
                            else//6
                            {
                                cout<<"PASSWORD IS NOT MATCHING!!"<<endl;
                                cout<<"Enter '1' to try again or enter '0' to return 'EXIT' :";

                                cin>>opz;
                                if(opz==1)
                                {
                                    att=3;
                                    while(att>0)
                                    {
                                        system("CLS");
                                        goto xyz;
                                        att--;
                                    }
                                    cout<<"TOO MANY UNSUCCESSFUL ATTEMPTS!! TRY AGAIN LATER!!"<<endl;
                                    system("CLS");
                                    goto mainmenu;
                                }
                                else
                                    {
                                        system("CLS");
                                        goto exit;}


                            }//6
                        }//4
                         else//7
                        {
                            cout<<"YOU HAVE ENTERED WRONG DOB!!"<<endl;
                            cout<<"Enter '1' to try again and enter '0' to EXIT :";

                            cin>>opz;
                            if(opz==1)
                            {
                                att=3;
                                while(att>0)
                                {
                                    system("CLS");
                                    goto abc;
                                    att--;
                                }
                                cout<<"TOO MANY UNSUCCESSFUL ATTEMPTS. TRY AGAIN LATER!!"<<endl;
                                cout<<"ENTER '1' TO RETURN TO MAIN MENU OR ENTER '0' TO EXIT : ";

                                cin>>opz;
                                if(opz==1)
                                    {
                                        system("CLS");
                                        goto mainmenu;}
                                else
                                    {
                                        system("CLS");
                                        goto exit;}
                            }
                            else
                               {
                                   system("CLS");
                                   goto exit;}
                        }
                    }


                    }


                }
                break;
            }




                case 3:
                    {
                        system("CLS");
                        goto exit;}
    }
    exit:
        cout<<"THANK YOU!!"<<endl;
        cout<<"HAVE A NICE DAY!!"<<endl;
        return 0;

}
