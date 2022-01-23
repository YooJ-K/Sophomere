using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20190411
{
    class 자동차
    {
        protected string 차종;
        protected int 차량번호;
        protected string 제조회사;

        virtual public void 차량정보() // virtual 메소드는 바디를 가지고 있어야한다.
        {
        }

        virtual public void 차정보()
        {

        }
    }

    sealed class 버스 : 자동차 // 이 클래스는 자식 클래스를 더이상 만들 수 없다.
    {
        protected int 버스번호;
        //부모 클래스의 필드들에 protected 없으면 차종. << 이렇게는 안됩니다. default 접근수정자 private
        void 차종출력()
        {
            Console.WriteLine(차종);
        }

        sealed override public void 차정보()   // sealed 다른 파생 클래스에서 차정보 메소드를 재정의 할 수 없게한다. 
        {

        }

        override public void 차량정보()
        {

        }
    }

    abstract class 이층버스
    {
        // 추상 메소드를 ㅅ가지고 있는것을 추상 클래스라고 한다
        abstract public void hello(); // private 붙을 수 ㅇㅄ다.
    }

    class 삼층버스 : 이층버스
    {
        override public void hello() // 이렇게 재정의 해줘야 사용가능합니당.
        {

        }
    }

    abstract class remote
    {
        abstract public void 전원켜기();
        abstract public void 전원끄기();
        abstract public void 메뉴열기();

        //일반 필드든 뭐든 다 만들수 있는데 객체만 못만든다.

    }

    class 도형
    {
        public void 무슨도형(도형 obj)
        {

        }
    }

    class 삼각형 : 도형
    {
        public void 이건무슨도형(도형 obj)
        {

        }
    }

    class samsungTV : remote
    {
        override public void 전원켜기() // 접근수정자 변경할수없다.
        {

        }
        override public void 전원끄기()
        {

        }
        override public void 메뉴열기()
        {

        }
    }


    class 자동차2
    {
        public int 차량번호;
    }

    class 바스 : 자동차2
    {
        public int 인승;
    }


    class Program
    {
        static void Main(string[] args)
        {
            버스 백11 = new 버스();
            이층버스 투어버스 = new 이층버스(); // 추상클래스는 객체를 만들 수 없다.

            도형 d = new 도형();
            삼각형 s = new 삼각형();
            d.무슨도형(d);
            d.무슨도형(s);
            
            s.이건무슨도형(s);
            s.이건무슨도형(d); //상향 형변환, 하향 형변환

            바스 _110 = new 바스();
            자동차2 페라리 = new 자동차2();
            자동차2 아벤타도르 = new 바스();// >> 부모가 가지고 있는거밖에 접근 못함
        }
    }


    
}
