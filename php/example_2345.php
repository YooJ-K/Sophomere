<?php
//예제 2-1 화면에 문장 출력하기
  echo "안녕하세요~~";
  //안녕하세요~~
?>

<?php
  //예제 2-2 주석문 사용하기
  //<?php는 PHP의 시작을 의미 echo문은 문자열을 브라우저 화면에 출력합니다.
  echo "안녕하세요~~";
  //안녕하세요~~
?>

<?php
//예제 2-3 상수와 변수 사용하기
 $a=10;
 $b=20;
 $c=$a+$b;
 echo "$c <br>";
 $a = 18.5;
 $b = 37.3;
 $c=$a+$b;
 echo"$c <br>";
 $fruit="사과";
 echo "$fruit <br>";
 $fruit="오렌지";
 echo "$fruit <br>";
 // 30 <br>55.8 <br>사과 <br>오렌지 <br>
?>

<!DOCTYPE html>
<html>
<!--echo문에서 문자열과 HTML 태그 출력하기-->
<head>
 <meta charset = 'utf-8'>
</head>

<body>
 <h3>
  <?php
   echo "고양이와 토끼";
  ?>
 </h3>
 <?php
  $filename = "cat.jpg";
  echo "<img src = '$filename'>";
  echo "<br>";
  $filename = "rabit.jpg";
  echo "<img src = '$filename'>";
  echo "<br>";
  //<!DOCTYPE html>
  //<html>
  //<head>
  // <meta charset = 'utf-8'>
  //</head>
  //<body>
  // <h3>
  //  고양이와 토끼 </h3>
  // <img src = 'cat.jpg'><br><img src = 'rabit.jpg'><br> </body>
  //</html>
 ?>
 </body>
</html>

<?php
//예제 2-5 큰따옴표와 작은 따옴표의 실행 결과가 같은 경우
  $name = "김유진";
  echo $name;
  echo "님 반갑습니다!";
  echo "<br>";

  $name = '김유진';
  echo $name;
  echo "님 반갑습니다!";

  //김유진님 반갑습니다!<br>김유진님 반갑습니다!
?>

<?php
//예제 2-6 큰따옴표와 작은따옴표의 실행 결과가 다른 경우
  $name="김유진";
  echo "$name 님 반갑습니다!";
  echo "<br>";

  $name='김유진';
  echo '$name 님 반갑습니다!';

  //김유진 님 반갑습니다!<br>$name 님 반갑습니다!
  //김유진님 반갑습니다! 김유진 님 반갑습니다!
?>

<?php
//예제 2-7 echo 문에서 변수명과 문자열이 붙어 있는 경우
  $name = "안지영";
  //echo "$name님 반갑습니다."; // 에러 뜬다 ==> 예제 2-8
?>

<?php
//예제 2-8 echo문 안의 변수명에 중괄호 사용하기
  $name = "안지영";
  echo "($name)님 반갑습니다.";
?>

<?php
//예제 2-9 큰따옴표 안에 큰따옴표 사용하기
  //echo "<img src = "cat.jpg">"; //에러
  echo "<img src='cat.jpg'>";
  echo "<img src = \"cat.jpg\">";
?>

<?php
 // echo문 안의 변수 값을 출력 할려면 무조건 큰따옴표를 써야한다
 $name="홍지수";
 echo "($name)님 반갑습니다";//(홍지수)님 반갑습니다
 echo "$name 님 반갑습니다";//홍지수 님 반갑습니다
 //echo "$name님 반갑습니다"; // 오류
 echo '$name 님 반갑습니다';//$name 님 반갑습니다
?>

<?php
 //예제 2-10 약식으로 echo문 표기하기
 $id="rubato";
 $name='루바토';
?>
<h3>회원정보</h3>
<p>- 아이디 : <?=$id?></p> // <?php echo "$id" ?>
<p>- 이름 : <?=$name?></p> // <?php echo "$name" ?>

<?php // 출력
 //<h3>회원정보</h3>
 //<p>- 아이디 : rubato</p> // rubato
 //<p>- 이름 : 루바토</p> // 루바토
?>

<?php
//예제 2-11 정수와 실수 사용하기
  $a = 3769;
  echo "\$a : $a";// \$a -> $a로 출력된다.
  echo "<br>";

  $a=126.7;
  echo "\$a : $a";
  echo "<br>";
  //$a : 3769<br>$a : 126.7<br>
?>

<?php
  //예제 2-12 문자열 사용하기
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
  //예제 2-14 산술 연산자 사용하기

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
  //예제 2-15 문자열 연결 연산자 사용하기

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
  // 예제 3-1 짝수/홀수 판별하기
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
  //예제 3-2 나이에 따라 입장료 판별하기

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
//예제 3-3 배수 판별하기 1
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
//예제 3-4 배수 판별하기2
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
//예제 3-5 회원 레벨에 따라 로그인 기능 판별하기

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
//예제 3-11 학년에 따라 급식비 계산하기

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
//예제 3-12 switch문 대신 if문 사용하기
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
//예제 4-1 while문으로 정수 1~10 출력하기
  $i=1;
  while($i<=10){
    echo "$i<br>";
    $i++;
  }
  echo "<br>";
  //1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br><br>
?>

<?php
//예제 4-2 while문으로 정수 1~10의 합계 구하기
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
//예제 4-3 while문으로 정수 100~300 중 3의 배수 합계 구하기
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
//에제 4-4 while문으로 정수 1~100 중 3의 배수가 아닌것들 출력하기
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
//예제 4-5 while문으로 인치를 센티미너로 변환하기
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

<?php
//예제 4-7 for문으로 정수 1~10 출력하기

  for($i=1; $i<=10; $i++){
    echo "$i<br>";
    //실행 순서 1) $i = 1 2) $i <= 10 3) echo 4) $i++
  }

  echo "<br>";


  //1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10<br><br>
?>

<?php
//예제 4-8 for문으로 정수 1~10의 합 구하기
  $sum = 0;

  for($a=1;$a<=10;$a++)
  {
    $sum+=$a;
  }

  echo "1에서 10까지 정수의 합은 $sum 입니다. <br>";

  //1에서 10까지 정수의 합은 55 입니다. <br>

  echo "<br>";

?>

<?php
//예제 4-9 for문으로 정수 1~100 중 5의 배수 합계 구하기
  $sum=0;
  for($i=1; $i<=100; $i++){
    if($i % 5 == 0){
      $sum+=$i;
    }
  }
  echo "1~100의 정수 중 5의 배수의 합계 : $sum<br><br>";

  //1~100의 정수 중 5의 배수의 합계 : 1050<br><br>
?>

<?php
//예제 4-10 for문으로 정수 500~700 중 4의 배수가 아닌 정수 출력하기
//$ok 변수의 유무로 차이 구하기

  $count = 0;
  for($i=500; $i<700; $i++){
    if($i%4!=0){
      echo $i." ";
      //echo에서의 . 의 의미는 +의 의미임!
      //echo $i.” “; => i값 출력되고 빈칸 출력

      $count++;
    }
    if($count!=0 && $count % 10 ==0){// 10개씩 출력하도록!
      echo "<br>";
    }
  }

  echo "==================================<br>";

$count = 0;
$ok = true;
  for($i=500; $i<700; $i++){
    if($i%4!=0){
      echo $i." ";
      $count++;
      $ok = true;
    }
    if($count!=0 && $count % 10 ==0 && $ok == true){
      echo "<br>";
      $ok=false;
    }
  }

//501 502 503 505 506 507 509 510 511 513 <br>
//514 515 517 518 519 521 522 523 525 526 <br>
//527 529 530 531 533 534 535 537 538 539 <br>
//<br>
//541 542 543 545 546 547 549 550 551 553 <br>
//554 555 557 558 559 561 562 563 565 566 <br>
//567 569 570 571 573 574 575 577 578 579 <br>
//<br>
//581 582 583 585 586 587 589 590 591 593 <br>
//594 595 597 598 599 601 602 603 605 606 <br>
//607 609 610 611 613 614 615 617 618 619 <br>
//<br>621 622 623 625 626 627 629 630 631 633
//<br>
//634 635 637 638 639 641 642 643 645 646 <br>
//647 649 650 651 653 654 655 657 658 659 <br>
//<br>
//661 662 663 665 666 667 669 670 671 673 <br>
//674 675 677 678 679 681 682 683 685 686 <br>
//687 689 690 691 693 694 695 697 698 699 <br>
//==================================<br>
//501 502 503 505 506 507 509 510 511 513 <br>
//514 515 517 518 519 521 522 523 525 526 <br>
//527 529 530 531 533 534 535 537 538 539 <br>
//541 542 543 545 546 547 549 550 551 553 <br>
//554 555 557 558 559 561 562 563 565 566 <br>
//567 569 570 571 573 574 575 577 578 579 <br>
//581 582 583 585 586 587 589 590 591 593 <br>
//594 595 597 598 599 601 602 603 605 606 <br>
//607 609 610 611 613 614 615 617 618 619 <br>
//621 622 623 625 626 627 629 630 631 633 <br>
//634 635 637 638 639 641 642 643 645 646 <br>
//647 649 650 651 653 654 655 657 658 659 <br>
//661 662 663 665 666 667 669 670 671 673 <br>
//674 675 677 678 679 681 682 683 685 686 <br>
//687 689 690 691 693 694 695 697 698 699 <br>

?>


<!--예제 4-11 for문으로 섭씨를 화씨로 변환하기 : 범위로 출력하겠구나!-->
<table border = "1" width = "300">
  <tr align = "center"><td width = "150">섭씨</td><td>화씨</td></tr>
  <?php
    for($c = -15; $c <= 35; $c +=5){
      $f = $c * 9 / 5 +32;
      echo "<tr aligne = 'center'><td>$c</td><td>$f</td></tr>";
    }

    //<tr aligne = 'center'><td>-15</td><td>5</td></tr>
    //<tr aligne = 'center'><td>-10</td><td>14</td></tr>
    //<tr aligne = 'center'><td>-5</td><td>23</td></tr>
    //<tr aligne = 'center'><td>0</td><td>32</td></tr>
    //<tr aligne = 'center'><td>5</td><td>41</td></tr>
    //<tr aligne = 'center'><td>10</td><td>50</td></tr>
    //<tr aligne = 'center'><td>15</td><td>59</td></tr>
    //<tr aligne = 'center'><td>20</td><td>68</td></tr>
    //<tr aligne = 'center'><td>25</td><td>77</td></tr>
    //<tr aligne = 'center'><td>30</td><td>86</td></tr>
    //<tr aligne = 'center'><td>35</td><td>95</td></tr>

    echo "<br>";
  ?>
</table>


<?php
//예제 4-12 이중 for문으로 구구단 표 만들기 1
  echo "<br>---------------------<br>";

  for($i = 1; $i <=9;$i++){
    for($j = 1; $j<=9;$j++){
      $sum = $i * $j;

      echo "$i x $j = $sum<br>";
    }

    echo "---------------------<br>";
  }
?>

<?php
//예제 4-13 이중 for문으로 구구단 표만들기 2
?>
<style media="screen">
  table{border-collapse; width=600px;}
  td{border:solid 1px gray; text-align:center; padding:5px;}
</style>
<h3>구구단 표</h3>
<table>
  <tr>
    <td>2단</td>
    <td>3단</td>
    <td>4단</td>
    <td>5단</td>
    <td>6단</td>
    <td>7단</td>
    <td>8단</td>
    <td>9단</td>
  </tr>
  <?php
    for($b=1;$b<=9;$b++){
      echo "<tr>";
      for($a=2;$a<=9;$a++){
        $c = $a + $b;
        echo "<td>{$a}x{$b}=$c</td>";
      }
      echo "</tr>";
    }
  ?>
</table>

<?php
//예제 4-14 이중 for문으로 별표 출력하기
  for($a=1;$a<=10;$a++){
    for($b=1;$b<=$a;$b++){
      echo "* ";
    }
    echo "<br>";
  }
?>

<?php
//예제 4-15 이중 for문으로 별표 출력하기2
  for($a=1;$a<=10;$a++){
    for($b=9;$b>=$a;$b--){
      echo "&nbsp;";
    }
    for($c=1;$c<=$a;$c++){
      echo "*";
    }
    echo "<br>";
  }
?>

<?php
//예제 4-16 while문으로 정수 1~10의 합계 구하기
  $i = 1;
  $sum = 0;

  while($i<=10){
    $sum+=$i;
    $i++;
  }
  echo "합계 : $sum";
?>

<?php
//예제 4-17 do ~ while 문으로 정수 1~10의 합계 구하기
  $i=1;
  $sum=0;

  do{
    $sum+=$i;
    $i++;
  }while($i<=10);

  echo "합계 : $sum";
?>

<?php
//예제 4-18 do ~ while문으로 10의 값 출력하기

  $i=10;

  do{
    print $i;
  }while($i<=1);
?>

<?php
//예제 4-19 while문으로 10의 값 출력하기
  $i = 10;

  while($i <= 1){
    print $i;
  }
?>

<?php
//예제 5-1 배열을 이용하여 성적의 합계와 평균 구하기
//배열을 이용하여 합계, 평균 구하기. 배열 원소는 0부터 시작한다.
   $score=array();
   $score[0]=90; // 영어 성적
   $score[1]=80; // 컴퓨터 개론 성적
   $score[2]=85; // 기초 프로그래밍 성적
   $score[3]=95; // 기초 수학 성적
   $score[4]=93; // 알고리즘 성적

   $sum = 0;
   for($a = 0; $a <=4; $a++){
      $sum+=$score[$a];
   }

   $avg = $sum/5;

   echo "과목 점수 : $score[0], $score[1], $score[2], $score[3], $score[4]<br>";
   echo "합계 : $sum, 평균 : $avg<br>";

   //과목 점수 : 90, 80, 85, 95, 93<br>합계 : 443, 평균 : 88.6<br>
?>

<?php
   // 예제 5-2 array() 함수를 이용하여 성적의 합계와 평균 구하기

   $scores = array(87,76,98,87,87,93,79,85,88,63,74,84,93,89,63,99,81,70,80,95);

   $sum = 0;

   for($a=0;$a<20;$a++){
      $sum =$sum + $scores[$a]; // 학생 20명의 성적 누적 합계
   }

   $avg = $sum/20;

   echo "합계 : $sum, 평균 : $avg";

   //합계 : 1671, 평균 : 83.55
?>

<?php
// 예제 5-3 배열을 이용하여 구구단 표 만들기
   $a = array();
   $b = array();
   $i=0; $j=0; $k=0; $c=0;
   for($i=0;$i<8;$i++){
      $a[$i] = $i + 2;
      echo $a[$i]." ";
   }

   echo "<br>";

   for($i=0;$i<9;$i++){
      $b[$i] = $i + 1;
      echo $b[$i]." ";
   }

   echo "<br>-----------------<br>";

   for($j=0;$j<9;$j++){
      $c = $a[0] * $b[$j];
      echo " $a[0] * $b[$j] = $c<br>";
   }

   echo "-----------------<br>";

   for($k=0;$k<9;$k++){
      $c = $a[4] * $b[$k];
      echo "$a[4] * $b[$k] = $c<br>";
   }

   echo "-----------------<br>";
?>

<?php
//예제 5-4 오름차순으로 버블 정렬하기

  $num = array(15, 13, 9, 7, 6, 12, 19, 30, 28, 26);
  $count = 10;

  echo "정렬 전 : ";
  for($a = 0; $a < 10; $a++)
    echo $num[$a]." ";

  echo "<br>";

  for($i=$count-2; $i>=0; $i--){
    for($j = 0; $j <= $i; $j++){
      if($num[$j] > $num[$j+1]){
        $tmp = $num[$j];
        $num[$j] = $num[$j+1];
        $num[$j+1]=$tmp;
      }
    }
  }

  echo "버블 정렬(오름차순) 후 : ";
  for($a=0; $a<10; $a++){
    echo $num[$a], " ";
  }
?>

<?php
//예제 5-5 2차원 배열을 이용하여 성적의 합계와 평균 구하기
//2차원 배열을 이용하여 학생 3명의 5개 과목 성적 합계와 평균 구하기
  $score = array(array(88, 98, 96, 77, 63),
    array(86, 77,66, 86, 93),
    array(74, 83, 95, 86, 97));

  for($i = 0; $i<3; $i++){
    for($j = 0; $j < 5; $j++){
      echo "\$score[$i][$j] = ".$score[$i][$j]."<br>";
    }
    echo "<br>";
  }

  // 학생 3명의 성적 합계와 평균

  for($i=0; $i<3; $i++){
    $sum = 0;
    for($j = 0; $j < 5; $j++){
      $sum+=$score[$i][$j];
    }

    $avg = $sum/5;
    $student_num = $i + 1;
    echo "$student_num 번 학생의 점수 => 합계 : $sum, 평균 : $avg <br>";
  }

?>
