
<?php
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
 // echo문 안의 변수 값을 출력 할려면 무조건 큰따옴표를 써야한다 
 $name="홍지수";

 echo "($name)님 반갑습니다";//(홍지수)님 반갑습니다
 echo "$name 님 반갑습니다";//홍지수 님 반갑습니다
 //echo "$name님 반갑습니다"; // 오류
 echo '$name 님 반갑습니다';//$name 님 반갑습니다
?>



<?php
 //약식으로 echo문 표기하기
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
