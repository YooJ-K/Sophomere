<!DOCTYPE html>
<html>

<head>
  <title>24 study cafe</title>
  <style media="screen">
  #g_line {
    width: 800px;
    background-color: #E2E2E2;
    border: 0px
  }

  #login_box {
    width: 430px;
    margin: 0 auto;
  }

  #login_box .num1 {
    float: left;
    width: 130px;
    margin-top: 4px;
  }

  #login_box .num2 {
    float: left;
    width: 300px;
  }

  #info {
    width: 300px;
    height:30px;
    font-size:20px
  }

  #login_button {
    text-align: center;
    position: relative;
    width: 2525px;
    margin: 0 auto;
  }
  </style>
</head>

<body>
  <center>
    <?php include "header.php";?>

    <hr size="5px" id="g_line">
    <h2 style="text-align: center">로그인</h2>
    <hr size="5px" id="g_line">
    <section id="login_box">

      <h3>
        <br><br>
        <div class="num1">
          아이디
        </div>
        <div class="num2">
          <input type="text" name="id" id="info" style="height:30px; font-size:20px">
        </div>
        <br><br><br>
        <div class="num1">
          비밀번호
        </div>
        <div class="num2">
          <input type="password" name="pass" id="info" style="height:30px; font-size:20px">
        </div>
      </h3>
      <br><br><br><br>



    </section>
    <div id="login_button">
      <input type="button" name="" value="로그인" style="width:100px;font-size:20px" onclick="login();">
    </div>
    <?php include "footer.php";?>
  </center>
</body>

</html>
