<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <title>24 study cafe</title>
  <script>
    function check() {

      if (!document.join.name.value) {
        alert("이름을 입력하세요!");
        document.join.name.focus();
        return;
      }

      if (!document.join.phone.value) {
        alert("휴대폰 번호를 입력하세요!");
        document.join.phone.focus();
        return;
      }

      if (!document.join.pass.value) {
        alert("비밀번호를 입력하세요!");
        document.join.pass.focus();
        return;
      }

      if (!document.join.pass_confirm.value) {
        alert("비밀번호확인을 입력하세요!");
        document.join.pass_confirm.focus();
        return;
      }

      if (!document.join.birth.value) {
        alert("생년월일을 입력하세요!");
        document.join.birth.focus();
        return;
      }

      if (document.join.pass.value !=
        document.join.pass_confirm.value) {
        alert("비밀번호가 일치하지 않습니다.\n다시 입력해 주세요!");
        document.join.pass.focus();
        document.join.pass.select();
        return;
      }

      if (!document.join.ag.checked) {
        alert("약관에 동의하세요!");
        document.join.ag.focus();
        return;
      }

      document.join.submit();
    }
  </script>

  <style media="screen">
    #join_box {
      width: 730px;
      margin: 0 auto;
    }

    #join_box .num1 {
      float: left;
      width: 130px;
      margin-top: 4px;
    }

    #join_box .num2 {
      float: left;
      width: 600px;
    }

    #info {
      width: 500px;
    }

    #g_line {
      width: 800px;
      background-color: #E2E2E2;
      border: 0px
    }

    #agree {
      text-align: center;
      position: relative;
      width: 2400px;
      margin: 0 auto;
    }

    #join_button {
      text-align: center;
      position: relative;
      width: 2525px;
      margin: 0 auto;
    }
  </style>
</head>

<body>
  <header>
    <?php include "header.php";?>
  </header>
  <section>
    <hr size="5px" id="g_line">
    <h2 style="text-align: center">회원 가입</h2>
    <hr size="5px" id="g_line">
    <br>
    <form name="join" action="insert.php" method="post">

      <h3>
        <div id="join_box">
          <div class="num1">
            이름
          </div>
          <div class="num2">
            <input type="text" name="name" id="info" style="height:30px; font-size:20px">
          </div>
          <br><br><br>

          <div class="num1">
            휴대폰번호
          </div>
          <div class="num2">
            <input type="tel" name="phone" id="info" style="height:30px; font-size:20px" placeholder="010-0000-0000">
          </div>
          <br><br><br>

          <div class="num1">
            비밀번호
          </div>
          <div class="num2">
            <input type="password" name="pass" id="info" style="height:30px; font-size:20px">
          </div>
          <br><br><br>

          <div class="num1">
            비밀번호확인
          </div>
          <div class="num2">
            <input type="password" name="pass_confirm" id="info" style="height:30px; font-size:20px">
          </div>
          <br><br><br>

          <div class="num1">
            생년월일
          </div>
          <input type="date" name="birth" id="info" style="height:30px; font-size:20px">
          <br><br><br><br>
      </h3>
      <div id="agree">
        <span><b>(필수)</b></span>개인정보 활용에 동의합니다.
        <input type="checkbox" name="ag">
      </div>

      <br>

      <div id="join_button">
        <input type="button" name="" value="가입하기" style="width:150px;font-size:20px" onclick="check();">
      </div>
    </form>
  </section>

  <br>

  <br>

  <?php include "footer.php";?>
</body>

</html>
