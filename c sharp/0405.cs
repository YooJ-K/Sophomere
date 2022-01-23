using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0405_이론_수업
{
    class 정수
    {
        int x; //x값 default = 0 
        public void setX(int num)
        {
            x = num;
        } // 매개변수가 달라야 메소드 오버로딩 쓸 수 있음.
        public int getX()
        {
            return x;
        }
    }


    //class default = internal
    class Program
    {
        int 변수;//그 클래스의 멤버, 멤버변수 = 필드
        //field default = private

        public static void 더하기(int x, int y) // 형식인자 : 2개
        {//public 누구든지 메소드에 접근 가능하다.
         // static 정적 메소드 : 객체가 아닌 클래스 단위로 접근 가능하다. Program.더하기(); 로!
            ++x;
            ++y;
            Console.WriteLine(x + y); // 더하기의 기능이 2개이다. 연산자오버로딩
        }


        public static void 더하기(정수 x, 정수 y)
        {
            Console.WriteLine((x.getX()) + (y.getX()));

            

        } // 메소드 오버로딩 : 이름 똑같아도 형식인자 다르면 사용 가능하다.

        static void Main(string[] args)
        {

            int x = 100;
            int y = 100;

            더하기(x, y); // 값호출

            정수 엑스 = new 정수();
            정수 와이 = new 정수();

            엑스.setX(1); // 엑스 객체의 필드 x 값이 1로 세팅
            와이.setX(1); // 와이 객체의 필드 y 값이 1로 세팅

            Console.WriteLine(엑스.getX());
            Console.WriteLine(와이.getX());

            더하기(엑스, 와이);//((엑스 객체 필드 x값을 하나 증가시켜서
            //엑스 객체 필드 x와 y객체 필드 x의 값을 더한다.

            Console.WriteLine(엑스.getX());
            Console.WriteLine(와이.getX());
        }
    }
}
