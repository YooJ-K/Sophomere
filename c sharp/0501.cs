using System;

class C
{
    virtual public void Print()
    {
        Console.WriteLine("C");
    }
}

class Java : C
{
    override public void Print()
    {
        Console.WriteLine("Java");
    }
}

class App
{
    public static void Main()
    {
        C q = new Java();
        q.Print();
    }
}