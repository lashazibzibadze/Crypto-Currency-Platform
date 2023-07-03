#include <iostream>
#include <string>
#include <random>
#include <unistd.h>
#include <stdlib.h>

// Author: Lasha Zibzibadze
// Crypto Currency Platform
// Allowing users to register, log in, log out. Play with Coins, and do many other fun things.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Class for menu
class crypto_menu
{
private:

    int wallet_balance;
    std::string username;
    std::string password;

public:
    //std::string pass;
    //int value = 0;
    int id;
    void set_password(std::string pass);
    void set_balance(int value);
    void set_id();
    void set_username(std::string usu);
    int get_id();
    int get_balance();
    std::string get_password();
    std::string get_username();
    crypto_menu(int x, std::string us, std::string pas);   
};

crypto_menu::crypto_menu(int x, std::string us, std::string pas)
{
    this->wallet_balance = 100;
    this->id = x;
    this->username = us;
    this->password = pas;    
}


std::string crypto_menu::get_username()
{
    return this->username;
}

void crypto_menu::set_password(std::string pass)
{
    this->password = pass;
}

void crypto_menu::set_username(std::string usu)
{
    this->username = usu;
}

std::string crypto_menu::get_password()
{
    return password;
}

void crypto_menu::set_balance(int value)
{
    wallet_balance = value;
}

void crypto_menu::set_id()
{
    id = rand();
}


int crypto_menu::get_id()
{
    return id;
}

int crypto_menu::get_balance()
{
    return wallet_balance;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void exit() // Pretty exit interface
{    
    std::cout<< std::endl << "'Exiting .";
    sleep(1);
    std::cout << " .";
    sleep(1);
    std::cout << " .";
    sleep(1);
    std::cout << " .'" << std::endl << std::endl;
    sleep(1);
}

void redirect() // Pretty redirect interface
{    
    std::cout<< std::endl << "'Loading Menu .";
    sleep(1);
    std::cout << " .";
    sleep(1);
    std::cout << " .";
    sleep(1);
    std::cout << " .'" << std::endl << std::endl;
    sleep(1);
}


void help(int experssion) //Help function :: Option 1
{
    switch (experssion)
    {
    case 1:
        std::cout << "Play as you wish and make profit or at least try to :) "<< std::endl << std::endl;
    case 2:
        std::cout << "If you have further questions please contact a specialist. "<< std::endl;
    case 3:
        exit();
        redirect();
        break;
    
    default:
        std::cout << "Wrong Input"<< std::endl;
        exit();
        break;
    }
}


int bid(int bet) //betting system
{
    int percentage= 1+ (rand() % 100);

    if(percentage > 25 )
    {
        std::cout<< "You lost your " << bet << " Coins  😢" << std::endl;
        return 0;
    }
    else
    {       
        std::cout << "Congratulations, you won " << bet * 2 << "Coins  😀 " << std::endl;
        return bet*3;
    }

}







int main()
{
    bool log_in = false;
    int random;
    std::string temp_user;
    std::string temp_pass;
    int menu_start;

    crypto_menu user(random, temp_user, temp_pass);

    std::cout << "Welcome to Crypto Currency Program" << std::endl <<std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout <<"1: Register new user " <<std::endl;
    std::cout << "(Every new user gets 100 free coins)" << std:: endl;
    std::cout <<"2: Exit " <<std::endl;
    std::cout << "===========================================" << std::endl;
    std::cin >> menu_start;

    if(menu_start == 1) //Registering a new user
    {
        std::cout << "Create your username: "<< std::endl;
        std::cin>> temp_user;
        std::cout << "Perfect your username is: " << temp_user << std::endl;
        std::cout << " " << std::endl;
        std::cout << "Create your password: " << std::endl;
        std::cin>> temp_pass;
        std::cout << "You are all set! Your password is: " << temp_pass << std::endl;
        random= rand();
        std::cout << "Your unique id has been created: " << random << std::endl;
        user.set_password(temp_pass);
        user.set_username(temp_user);

        std::cout << "Remember your password: " << user.get_password() << std::endl << std::endl <<  "You are now Logged in !" << std::endl;
        log_in = true;
    }

    else if(menu_start == 2)
    {
        exit();
        return 0;
    }

    else
    {
        std::cout<< "Invalid input! " << std::endl;
        exit();
        return 0;
    }

    //Menu loop
    while(true)
    {

        //Menu
        std::cout << " " <<std::endl;

        std::cout<< "1: Print help " << std::endl;
        std::cout<< "2: Print exchange stats " << std::endl;
        std::cout<< "3: Make an exchange " << std::endl;
        std::cout<< "4: Make a bid (Winning chance 25%) " << std::endl;
        std::cout<< "5: Print wallet " << std::endl;
        std::cout<< "6: Continue " << std::endl;
        std::cout<< "7: Log in" <<std::endl;
        std::cout<< "8: Log out / Exit" <<std::endl;
        std::cout<< "9: Check your profile" <<std::endl;
        std::cout<< "========================"<< std::endl;

        int user_selection;
        std::cout<< "Select an option 1-9 : ";
        std::cin>> user_selection;
        std::cout << "You chose: " << user_selection << std::endl;
        std::cout << "     " << std::endl;

        if(user_selection > 9 || user_selection == 0 || user_selection < 0)
        {
            std::cout<< "Wrong input! "<< std::endl;
            redirect();
        }
        else
        {
            if(user_selection == 1) //Print Help
            {
                int x;
                std::cout<< "Write 1 or 2 and 3(exit) for help"<< std::endl;
                std::cin>> x;
                help(x);

            }

            if(user_selection == 2 && log_in == true) //Exchange stats
            {
                std::cout << "Exchange stats are as follows: "<< std::endl;
                std::cout << "1 Coin = 100 $ "<< std::endl;
                std::cout << "10 Coin = 1000 $"<< std::endl;
                std::cout << "100 Coin = 10000 $"<< std::endl;

                sleep(2);
                redirect();
            }
            else if(user_selection == 2 && log_in == false)
            {
                std::cout << "Log in or register to access this data!" << std::endl;
                sleep(2);
            }

            if(user_selection == 3 && log_in == true) //Make an offer
            {
                int coins_cashout;
                std::cout << "How many coins would you like to cash out? : "<< std::endl;
                std::cin >> coins_cashout;
                bool success= false;

                if(user.get_balance() >= coins_cashout)
                {
                    user.set_balance(user.get_balance() - coins_cashout);
                    std::cout << "The following amount will be wired to your account: "<< coins_cashout * 100 << std::endl;
                    success = 1;
                }
                else
                {
                    std::cout << "You don't have enough coins to complete the transaction! "<< std::endl;
                }

                std::cout << "Your new balance: "<< user.get_balance()<< std::endl;

                if(success == 1)
                {
                    std::cout << "You cashed out successfully "<< coins_cashout * 100 << " USD" <<  std::endl;
                }
                else
                {
                    std::cout << "Operation failed, try again! " << std::endl;
                }
                exit();
                redirect();
            }
            else if(user_selection == 3 && log_in == false) //Make an offer
            {
                std::cout << "Log in or register to access this data!" << std::endl;
                sleep(2);
            }

            if(user_selection == 4 && log_in == true) //Make a bid
            {
                int bet=0;
                std::cout << "Okay, Accepting bids"<< std::endl << "How much would you like to bet? (Profit 2x) (Minimum bid: 2 Coins)" << std::endl;
                std::cin>> bet;


                if(bet > 1)
                {
                    if(user.get_balance() > bet)
                    {
                        if(bid(bet) == 0)
                        {
                            user.set_balance(user.get_balance() - bet);
                        }
                        else
                        {
                            user.set_balance(user.get_balance() + bet);
                        }

                        std::cout<< "Your new balance: " << user.get_balance() << std::endl;

                    }
                    else
                    {
                        std::cout<< "You don't have enough coins for transaction! Try again. " << std::endl;
                        std::cout<< "Your balance: " << user.get_balance() << std::endl;
                    }

                }
                else
                {
                    std::cout<< "Minimum bid is 2 Coins, try again! " << std::endl;
                }


                exit();
                redirect();

            }
            else if(user_selection == 4 && log_in == false) //Make a bid
            {
                std::cout << "Log in or register to access this data!" << std::endl;
                sleep(2);
            }

            if(user_selection == 5 && log_in == true) //Print wallet
            {
                std::cout << "Your wallet information: "<< user.get_balance() << " Coins" << std::endl;
                exit();
                redirect();

            }
            else if(user_selection == 5 && log_in == false) //Print wallet
            {
                std::cout << "Log in or register to access this data!" << std::endl;
                exit();
                redirect();
            }

            if(user_selection == 6) //Continue
            {
                std::cout << "Continue"<< std::endl;
                sleep(2);
            }


            if(user_selection == 7)
            {
                std::string check_id;
                std::cout<< "Enter your username: " << std::endl;
                std::cin>> check_id;
                if(user.get_username() == check_id )
                {
                    std::string check_password;
                    std::cout<< "Enter your password: "<< std::endl;
                    std::cin>> check_password;
                    std::cout << " " <<std::endl;
                    std::cout << "You entered: " << check_password<< std::endl;

                    if(check_password == user.get_password())
                    {
                        std::cout<< "You have been succesfully logged in!" << std::endl;
                        log_in = true;
                        sleep(2);
                    }
                    else
                    {
                        std::cout<< "Password incorrect!" << std::endl;
                        log_in = false;
                        sleep(2);
                    }
                }
                else
                {
                    std::cout<< "Username not found, try again" << std::endl;
                    redirect();
                }

            }

            if(user_selection == 8)
            {
                std:: cout<< " " <<std::endl;
                std:: cout<< "Success, Logging out" <<std::endl;
                exit();
                log_in = false;
                break;

            }

            if(user_selection == 9) // Profile Checking
            {
                std::cout<< "Re-enter your password: " << std::endl;
                std::string re_pass;
                std::cin>> re_pass;
                if(re_pass == user.get_password())
                {
                    std::cout<< "Your id number: " << user.get_id() << std::endl;
                    std::cout<< "Your username: " << user.get_username() << std::endl;
                    std::cout<< "Your password: " << user.get_password() << std::endl;
                    std::cout<< "Your balance: "  << user.get_balance() << std::endl;
                    exit();
                    redirect();                
                }
                else
                {
                    log_in = false;
                    std::cout << "Wrong password, go authorize again by choosing option 7" << std::endl;
                    exit();
                    redirect();
                }
            }

            }
        

    }
    return 0;
}

