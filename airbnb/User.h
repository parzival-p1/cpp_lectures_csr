#ifndef USER_H
#define USER_H


class User
{
    public:
        User();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string GetlastName() { return lastName; }
        void SetlastName(string val) { lastName = val; }
        string Getdestiny() { return destiny; }
        void Setdestiny(string val) { destiny = val; }
        int GetcheckIn() { return checkIn; }
        void SetcheckIn(int val) { checkIn = val; }
        int GetcheckOut() { return checkOut; }
        void SetcheckOut(int val) { checkOut = val; }
        int GetguestsNumber() { return guestsNumber; }
        void SetguestsNumber(int val) { guestsNumber = val; }
        string Getmessages() { return messages; }
        void Setmessages(string val) { messages = val; }
        string Getwhishlists() { return whishlists; }
        void Setwhishlists(string val) { whishlists = val; }
        string Gethelp() { return help; }
        void Sethelp(string val) { help = val; }
        bool GetlogOut() { return logOut; }
        void SetlogOut(bool val) { logOut = val; }

        string name;
        string lastName;
        string destiny;
        int checkIn;
        int checkOut;
        int guestsNumber;

    protected:

    private:
        string messages;
        string whishlists;
        string help;
        bool logOut;
};

#endif // USER_H
