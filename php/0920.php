<?php
//예제 2-11
  $a = 3769;
  echo "\$a : $a";// \$a -> $a로 출력된다.
  echo "<br>";

  $a=126.7;
  echo "\$a : $a";
  echo "<br>";
  //$a : 3769<br>$a : 126.7<br>
?>

<?php
  //예제 2-12
  $title = "<h3>연락처</h3>";
  $name = "홍길동";
  $address = "경기도 성남시 분당구";
  $phone = "010-1234-5678";
  $email = "user@codingschool.biz";

  echo $title;
  echo "이름 : $name<br>";
  echo "주소 : $address<br>";
  echo "전화번호 : $phone<br>";
  echo "이메일 : $email<br>";
  echo "<br>";

  //<h3>연락처</h3>이름 : 홍길동<br>
  //주소 : 경기도 성남시 분당구<br>
  //전화번호 : 010-1234-5678<br>
  //이메일 : user@codingschool.biz<br><br>
?>

<?php
  //2-13 bool 데이터형 사용하기

  $a=true;
  $b=false;

  echo $a; // 1출력
  echo "<br>";
  echo $b; // 아무것도 출력하지 않는다.
  echo "<br>";

  //1<br><br>
?>

<?php
  //예제 2-14

  $a = 3;//a=3
  $b = 5;//a=3 b=5

  $c = $a + $b;// a=3 b=5 c=8
  $c++;// a=3 b=5 c=9

  $c += $a;// a=3 b=5 c=12
  $d = $a + $c * $b;// a=3 b=5 c=12 d=63

  echo "\$d : $d";
  echo "<br>";

  $a =10;// a=10 b=5 c=12 d=63
  $b=$a%3;// a=10 b=1 c=12 d=63
  $b--;// a=10 b=0 c=12 d=63

  $c = $a -$b;// a=10 b=0 c=10 d=63
  $c=$c-5;// a=10 b=0 c=5 d=63

  echo "\$c : $c";
  echo "<br>";
  echo "<br>";

  //$d : 63<br>$c : 5<br><br>
?>

<?php
  //예제 2-15

  $num1 = "010";
  $num2 = "1234";
  $num3 = "5678";
  $phone_number = $num1."-".$num2."-".$num3;
  echo "휴대폰 번호 : $phone_number"."<br>";

  $email1 = "admin";
  $email2 = "codingschool.info";
  $email = $email1."@".$email2;
  echo "이메일 주소 : $email";

  echo "<br>";
  echo "<br>";
  //휴대폰 번호 : 010-1234-5678<br>
  //이메일 주소 : admin@codingschool.info<br><br>
?>

<?php
//예제 2-16 대입 연산자 사용하기
  $a=5;
  echo $a."<br>";

  $a+=3;
  echo $a."<br>";

  $a-=4;
  echo $a."<br>";

  $a *= 2;
  echo $a."<br>";

  $a/=4;
  echo $a."<br>";

  $a %=2;
  echo $a."<br>";

  $a = "딸기";
  $a .=" 주스"; // $a = $a. " 주스"와 동일
  echo $a."<br>";

  echo "<br>";

  //5<br>8<br>4<br>8<br>2<br>0<br>딸기 주스<br><br>

?>

<?php
  // 예제 3-1
  $n = 27;

  if($n%2==0){
    echo "$n : 짝수";
  }
  else{
    echo "$n : 홀수";
  }
  echo "<br>";
  echo "<br>";

  //27 : 홀수<br><br>
?>

<?php
  //예제 3-2

  $age = 66;
  $fee = "5000원";

  if($age>=65){
    $fee = "무료";
  }

  echo"나이 : $age 세<br>";
  echo "입장료 : $fee";

  echo "<br>";

  //나이 : 66 세<br>입장료 : 무료<br>
?>

<?php
//예제 3-3
  $num = 32;
  $result = "3의 배수도 5의 배수도 아니다.";

  if($num %3==0)
    $result = "3의 배수이다.";

  if($num % 5 == 0)
    $result = "5의 배수이다.";

  if($num % 5 == 0 && $num %3==0)
    $result = "3의 배수이면서 5의 배수이다.";

  echo "$num : $result";

  echo "<br>";
  echo "<br>";

  //32 : 3의 배수도 5의 배수도 아니다.<br><br>
?>

<?php
//예제 3-4
  $besu = 3;
  $num = 12;

  if($num % $besu ==0){
    echo "$num : $besu"."의 배수이다.";
  } else{
    echo "$num : $besu"."의 배수가 아니다.";
  }
  echo "<br>";
  echo "<br>";
  //12 : 3의 배수이다.<br>
?>

<?php
//예제 3-5

  $level = 7;
  echo "회원 레벨 : $level<br>";

  if($level >= 1 and $level <=7)
    echo "로그인 가능합니다!";
  else {
    echo "로그인이 가능하지 않습니다!";
  }
  echo "<br>";

  //회원 레벨 : 7<br>로그인 가능합니다!<br>
?>

<?php
  //예제 3-2

  $age = 66;
  $fee = "5000원";

  if($age>=65){
    $fee = "무료";
  }

  echo"나이 : $age 세<br>";
  echo "입장료 : $fee";

  echo "<br>";

  //나이 : 66 세<br>입장료 : 무료<br>
?>

<?php
//예제 3-3
  $num = 32;
  $result = "3의 배수도 5의 배수도 아니다.";

  if($num %3==0)
    $result = "3의 배수이다.";

  if($num % 5 == 0)
    $result = "5의 배수이다.";

  if($num % 5 == 0 && $num %3==0)
    $result = "3의 배수이면서 5의 배수이다.";

  echo "$num : $result";

  echo "<br>";
  echo "<br>";

  //32 : 3의 배수도 5의 배수도 아니다.<br><br>
?>

<?php
//예제 3-4
  $besu = 3;
  $num = 12;

  if($num % $besu ==0){
    echo "$num : $besu"."의 배수이다.";
  } else{
    echo "$num : $besu"."의 배수가 아니다.";
  }
  echo "<br>";

  //12 : 3의 배수이다.<br>
?>

<?php
//예제 3-5

  $level = 7;
  echo "회원 레벨 : $level<br>";

  if($level >= 1 and $level <=7)
    echo "로그인 가능합니다!";
  else {
    echo "로그인이 가능하지 않습니다!";
  }
  echo "<br>";
  echo "<br>";

  //회원 레벨 : 7<br>로그인 가능합니다!<br>
?>

<?php
//예제 3-6
//체중 조절이 필요한지 판별 : 몸무게가 (키-100)*0.9보다 크면 체중 조절 필요

  $h=170;
  $w=50;
  $a=($h-100)*0.9;

  echo "키 : $h<br>";
  echo "몸무게 : $w<br>";

  if($w > $a) echo "체중 조절이 필요합니다. <br>";
  else echo "체중 조절이 필요하지 않습니다.<br>";

  echo "<br>";

  //키 : 170<br>몸무게 : 50<br>체중 조절이 필요하지 않습니다.<br><br>

?>

<?php
//예제 3-7 점수에 따라 등급 판별하기

  $score = 83;

  if($score >= 95) $grade = "A+";
  elseif($score>=90) $grade = "A";
  elseif($score >= 85) $grade = "B+";
  elseif($score >= 80) $grade = "B";
  elseif($score >= 75) $grade = "C+";
  elseif($score >= 70) $grade = "C";
  elseif($score >= 65) $grade = "D+";
  elseif($score >= 60) $grade = "D";
  else $grade = "F";

  //php는 다른 언어들과 다르게 elseif를 붙여 쓰는거 같다.

  echo "입력된 점수는 $score 점 입니다.<br>";
  echo "$grade 등급 입니다.<br><br>";

  //입력된 점수는 (83)점 입니다.<br>B 등급 입니다.<br><br>
?>

<?php
//예제 3-8 놀이공원 입장료 계산하기
  $age = 68;
  $welfare = "no"; // 복지카드 유무
  $youkong = "yes"; // 국가유공자증 유무
  $after = "no"; // yes : 17시 이후 입장 no : 17시 이전 입장

  if($age<3) $fee = "무료";
  elseif($age<=13 || $after=="yes") $fee = "4000원";
  elseif($age <= 18 || $age>=70 || $welfare == "yes" || $youkong == "yes") $fee = "8000원";
  else $fee = "10000원";

  echo "복지 카드 소지 : $welfare<br>";
  echo "국가 유공자증 소지 : $youkong<br>";
  echo "17시 이후 입장 : $welfare<br>";
  echo "나이 : $age<br><br>";
  echo "입장료 : $fee<br><br>";

//복지 카드 소지 : no<br>국가 유공자증 소지 : yes<br>17시 이후 입장 : no<br>나이 : 68<br><br>입장료 : 8000원<br><br>
?>

<?php
//예제 3-9 정수 3개를 값이 큰 순서로 정렬하기 중첩 if문 사용
  $a = 2;
  $b=6;
  $c=9;

  if($a>$b){
    if($a>$c){
      $max1 = $a;
      if($b > $c) {
        $max2 = b;
        $max3=c;
      }


      else{
        $max2 = c;
        $max3=b;
      }
    }
    else{
      $max1=$c;
      $max2 = $a;
      $max3= $b;
    }
  }
  else{
    if($b > $c){
      $max1 = $b;
      $max2 = $c;
      $max3 = $a;
    }
    else{
      $max1 = $c;
      $max2 = $b;
      $max3 = $a;
    }
  }

  echo "a : $a b : $b c : $c<br>";
  echo "큰 수대로 배열 $max1 $max2 $max3<br><br>";

?>

<?php
//예제 3-10
//출생한 연, 월, 일에 따라 만 나이 계산하기
  $now_year=2019;
  $now_month=3;
  $now_day=10;
  $birth_year=1990;
  $birth_month=3;
  $birth_day=30;

  if($birth_month<$now_month){
    $age=$now_year-bith_year;
  }
  elseif($birth_month==$now_month){
    if($birth_day<=$now_day){
      $age = $now_year-$birth_year;
    }
    else{
      $age = $now_year-$birth_year-1;
    }
  }
  else{
    $age=$now_year-$birth_year-1;
  }
  echo "오늘 날짜 : $now_year 년 $now_month 월 $now_day 일<br>";
  echo "출생 연월일 : $birth_year 년 $birth_month 월 $birth_day 일<br>";
  echo "만 나이 : $age 세<br><br>";

//오늘 날짜 : 2019 년 3 월 10 일<br>출생 연월일 : 1990 년 3 월 30 일<br>만 나이 : 28 세<br><br>
?>

<?php
//예제 3-11

  $grade = 5;
  switch ($grade) {
    case 1:
      echo "$grade 학년 급식비 : 3만원";
      break;
    case 2:
      echo "$grade 학년 급식비 : 3만5천원";
      break;
    case 3:
        echo "$grade 학년 급식비 : 4만원";
        break;
    case 4:
        echo "$grade 학년 급식비 : 4만5천원";
        break;
    case 5:
        echo "$grade 학년 급식비 : 5만원";
        break;
    case 6:
        echo "$grade 학년 급식비 : 5만5천원";
        break;
    default:
      echo "학년이 잘못 입력되었어요!";
      break;
  }
  echo "<br><br>";
//5 학년 급식비 : 5만원<br><br>
?>

<?php
//예제 3-12
  $grade =5;
  if($grade==1){
    echo "$grade 학년 급식비 : 3만원";
  }
  elseif($grade==2){
    echo "$grade 학년 급식비 : 3만5천원";
  }
  elseif($grade==3){
    echo "$grade 학년 급식비 : 4만원";
  }
  elseif($grade==4){
    echo "$grade 학년 급식비 : 4만5천원";
  }
  elseif($grade==5){
    echo "$grade 학년 급식비 : 5만원";
  }
  elseif($grade==5){
    echo "$grade 학년 급식비 : 5만5천원";
  }
  else{
    echo "학년이 잘못 입력되었어요";
  }
  echo "<br><br>";

  //5 학년 급식비 : 5만원<br><br>
?>

<?php
//예제 4-1
  $i=1;
  while($i<=10){
    echo "$i<br>";
    $i++;
  }
  echo "<br>";
  //1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br><br>
?>

<?php
//예제 4-2
 $sum=0;
 $i=1;
 while($i<=10){
   $sum=$sum+$i;
   echo "\$i : $i -> 합계 : $sum<br>";
   $i++;
 }
 echo "<br>";
//$i : 1 -> 합계 : 1<br>$i : 2 -> 합계 : 3<br>$i : 3 -> 합계 : 6<br>
//$i : 4 -> 합계 : 10<br>$i : 5 -> 합계 : 15<br>$i : 6 -> 합계 : 21<br>
//$i : 7 -> 합계 : 28<br>$i : 8 -> 합계 : 36<br>$i : 9 -> 합계 : 45<br>
//$i : 10 -> 합계 : 55<br><br>
?>

<?php
//예제 4-3
  $sum=0;
  $i=100;
  while($i<=300){
    if($i%3==0){
      $sum=$sum+$i;
    }
    $i++;
  }
  echo "100~300까지의 정수 중 3의 배수의 합 : $sum<br><br>";
//100~300까지의 정수 중 3의 배수의 합 : 13467<br><br>
?>

<?php
//에제 4-4 3의 배수가 아닌것들 출력하기
  $i=1;
  $count =0;
  while($i<=100){
    if($i%3!=0){
      echo "$i ";
      $count++;
    }
    if($count %10==0){
      echo "<br>";
    }
    $i++;
  }

  echo "<br><br>";
  //1 2 4 5 7 8 10 11 13 14 <br><br>
  //16 17 19 20 22 23 25 26 28 29 <br><br>
  //31 32 34 35 37 38 40 41 43 44 <br><br>
  //46 47 49 50 52 53 55 56 58 59 <br><br>
  //61 62 64 65 67 68 70 71 73 74 <br><br>
  //76 77 79 80 82 83 85 86 88 89 <br><br>
  //91 92 94 95 97 98 100
?>

<?php
//예제 4-5
  $inch=10;
  echo "<table border='1'>";
  echo "<tr>";
  echo "<th width ='100'>인치</th><th width='100'>센티미터</th>";
  echo "<tr>";

  while($inch <= 100){
    $cm=$inch*2.54;
    echo "<tr align='center'><td>$inch</td><td>$cm</td></tr>";
    $inch=$inch+10;
  }

  echo "</table>";
//<table border='1'><tr><th width ='100'>인치</th><th width='100'>센티미터</th>
//<tr><tr align='center'><td>10</td><td>25.4</td></tr>
//<tr align='center'><td>20</td><td>50.8</td></tr><tr align='center'>
//<td>30</td><td>76.2</td></tr><tr align='center'><td>40</td><td>101.6</td></tr>
//<tr align='center'><td>50</td><td>127</td></tr><tr align='center'>
//<td>60</td><td>152.4</td></tr><tr align='center'><td>70</td><td>177.8</td></tr>
//<tr align='center'><td>80</td><td>203.2</td></tr><tr align='center'>
//<td>90</td><td>228.6</td></tr><tr align='center'><td>100</td><td>254</td></tr></table>
?>

<!-- 예제 4-6 -->
<h3>2단 구구단 표 만들기</h3>
<table border="1" width="100">
<?php
  $a=2;
  $b=1;
  while($b<=9){
    $c=$a+$b;
    echo "<tr><td align='center'>$a x $b= $c</td></tr>";
    $b++;
  }

//<tr><td align='center'>2 x 1= 3</td></tr><tr><td align='center'>2 x 2= 4</td></tr>
//<tr><td align='center'>2 x 3= 5</td></tr><tr><td align='center'>2 x 4= 6</td></tr>
//<tr><td align='center'>2 x 5= 7</td></tr><tr><td align='center'>2 x 6= 8</td></tr>
//<tr><td align='center'>2 x 7= 9</td></tr><tr><td align='center'>2 x 8= 10</td></tr>
//<tr><td align='center'>2 x 9= 11</td></tr>
?>
