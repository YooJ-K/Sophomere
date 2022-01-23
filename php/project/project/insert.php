<?php
  $name=$_POST["name"];
  $phone=$_POST["phone"];
  $pass=$_POST["pass"];
  $birth = date('Y-m-d', strtotime($_POST['birth']));

  $con = mysqli_connect("localhost","user1","12345","sample");

  $sql="insert into members(name,phone,pass,birth)";
  $sql.="value('$name','$phone','$pass','$birth')";

  mysqli_query($con,$sql);
  mysqli_close($con);

  echo "
    <script>
      location.href='main.php'
    </script>
  ";
?>
