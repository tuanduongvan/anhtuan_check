class HP
{
    protected:
        int maHP;
        int sl;
    public:
        HP(int = 0, int = 0);
        ~HP();
        void showHP();
        virtual void show();
};