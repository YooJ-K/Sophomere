<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <title>SS study cafe</title>
  <style media="screen">
    /* 마진 패딩 초기화 */
    * {
      padding: 0;
      margin: 0;
    }

    /* 페이지 기본 글꼴과 크기 설정 */
    body {
      font-family: "돋움";
      font-size: 14px;
    }

    img {
      border: 0;
    }

    ul {
      list-style-type: none;
    }

    /* <a> 태그 기본 설정 */
    a {
      display: inline-block;
      text-decoration: none;
    }

    a:link {
      text-decoration: none;
      color: #222222;
    }

    a:hover {
      text-decoration: none;
      color: #222222;
    }

    a:visited {
      text-decoration: none;
      color: #222222;
    }

    a:active {
      text-decoration: none;
      color: #222222;
    }

    /* 상단 헤더 */
    #top {
      position: relative;
      width: 1000px;
      height: 80px;
      margin: 0 auto;
    }

    #top h3 {
      position: absolute;
      top: 25px;
      left: 40px;
      font-size: 16px;
    }

    #top #top_menu {
      float: right;
      margin: 30px 60px 0 0;
    }

    #top #top_menu li {
      display: inline;
    }

    #menu_bar {
      height: 48px;
      background-color: #443e58;
      font-size: 16px;
    }

    #menu_bar ul {
      width: 1000px;
      margin: 0 auto;
      padding: 14px 0 0 40px;
    }

    #menu_bar li {
      display: inline;
      margin-left: 90px;
      color: white;
    }

    #menu_bar a:link {
      color: white;
    }

    #menu_bar a:hover {
      color: white;
    }

    #menu_bar a:visited {
      color: white;
    }

    #menu_bar a:active {
      color: white;
    }

    /* 메인 이미지 */
    #main_img_bar {
      height: 230px;
      text-align: center;
      background-color: white;
    }

    #main_img_bar img {
      margin-top: 30px;
    }

    /* 하단 푸터 */
    footer {
      height: 100px;
      background-color: #2c2a29;
    }

    #footer_content {
      position: relative;
      width: 1000px;
      margin: 0 auto;
      color: #dddddd;
    }

    #footer_logo {
      position: absolute;
      top: 30px;
      left: 50px;
      font-size: 16px;
    }

    #footer_logo span {
      color: yellow;
    }

    #download {
      position: absolute;
      top: 20px;
      left: 400px;
    }

    #author {
      position: absolute;
      top: 20px;
      left: 700px;
    }

    /* 메인 콘텐트 */
    #main_content {
      position: relative;
      width: 1000px;
      height: 400px;
      margin: 0 auto;
    }

    /* 가입 양식 폼 */
    #join_box {
      width: 600px;
      margin: 0 auto;
    }

    #join_box h2 {
      border-bottom: solid 1px #dddddd;
      padding-top: 50px;
    }

    #join_box .col1 {
      float: left;
      width: 110px;
      margin-top: 4px;
    }

    #join_box .col2 {
      float: left;
      width: 400px;
    }

    #join_box .col3 {
      float: left;
    }

    #join_box .form input {
      width: 390px;
      height: 22px;
    }

    #join_box .form {
      height: 38px;
    }

    #join_box .id {
      margin-top: 20px;
    }

    #join_box input[name=email1] {
      width: 100px;
    }

    #join_box input[name=email2] {
      width: 275px;
    }

    #join_box .bottom_line {
      margin-top: 10px;
      border-bottom: solid 1px #cccccc;
    }

    #join_box .buttons {
      text-align: right;
      margin: 20px 100px 0 0;
    }
  </style>
  <script>
    function check_input() {
      if (!document.member_form.id.value) {
        alert("아이디를 입력하세요!");
        document.member_form.id.focus();
        return;
      }

      if (!document.member_form.pass.value) {
        alert("비밀번호를 입력하세요!");
        document.member_form.pass.focus();
        return;
      }

      if (!document.member_form.pass_confirm.value) {
        alert("비밀번호확인을 입력하세요!");
        document.member_form.pass_confirm.focus();
        return;
      }

      if (!document.member_form.name.value) {
        alert("이름을 입력하세요!");
        document.member_form.name.focus();
        return;
      }

      if (!document.member_form.email1.value) {
        alert("이메일 주소를 입력하세요!");
        document.member_form.email1.focus();
        return;
      }

      if (!document.member_form.email2.value) {
        alert("이메일 주소를 입력하세요!");
        document.member_form.email2.focus();
        return;
      }

      if (document.member_form.pass.value !=
        document.member_form.pass_confirm.value) {
        alert("비밀번호가 일치하지 않습니다.\n다시 입력해 주세요!");
        document.member_form.pass.focus();
        document.member_form.pass.select();
        return;
      }

      document.member_form.submit();
    }

    function reset_form() {
      document.member_form.id.value = "";
      document.member_form.pass.value = "";
      document.member_form.pass_confirm.value = "";
      document.member_form.name.value = "";
      document.member_form.email1.value = "";
      document.member_form.email2.value = "";
      document.member_form.id.focus();
      return;
    }

    function check_id() {
      window.open("member_check_id.php?id=" + document.member_form.id.value,
        "IDcheck",
        "left=700,top=300,width=350,height=200,scrollbars=no,resizable=yes");
    }
  </script>
</head>

<body>
  <header>
    <?php
    session_start();
    if (isset($_SESSION["userid"])) $userid = $_SESSION["userid"];
    else $userid = "";
    if (isset($_SESSION["username"])) $username = $_SESSION["username"];
    else $username = "";
    if (isset($_SESSION["userlevel"])) $userlevel = $_SESSION["userlevel"];
    else $userlevel = "";
    if (isset($_SESSION["userpoint"])) $userpoint = $_SESSION["userpoint"];
    else $userpoint = "";
?>
    <div id="top">
      <h3>
        <a href="index.php">PHP 프로그래밍 입문</a>
      </h3>
      <ul id="top_menu">
        <?php
    if(!$userid) {
?>
        <li><a href="member_form.php">회원 가입(11장)</a> </li>
        <li> | </li>
        <li><a href="login_form.php">로그인(12장)</a></li>
        <?php
    } else {
                $logged = $username."(".$userid.")님[Level:".$userlevel.", Point:".$userpoint."]";
?>
        <li><?=$logged?> </li>
        <li> | </li>
        <li><a href="logout.php">로그아웃(12장)</a> </li>
        <li> | </li>
        <li><a href="member_modify_form.php">정보 수정(12장)</a></li>
        <?php
    }
?>
        <?php
    if($userlevel==1) {
?>
        <li> | </li>
        <li><a href="admin.php">관리자 모드(15장)</a></li>
        <?php
    }
?>
      </ul>
    </div>
    <div id="menu_bar">
      <ul>
        <li><a href="index.php">HOME</a></li>
        <li><a href="message_form.php">쪽지 만들기(13장)</a></li>
        <li><a href="board_form.php">게시판 만들기(14장)</a></li>
        <li><a href="index.php">사이트 완성하기(15장)</a></li>
      </ul>
    </div>
  </header>
  <section>
    <div id="main_img_bar">
      <img src="header.png" width="1080">
    </div>
    <div id="main_content">
      <div id="join_box">
        <form name="member_form" method="post" action="member_insert.php">
          <h2>회원 가입</h2>
          <div class="form id">
            <div class="col1">아이디</div>
            <div class="col2">
              <input type="text" name="id">
            </div>
				        <div class="col3">
				        	<a href="#"><img src="check_id.gif"
				        		onclick="check_id()"></a>
				        </div>
			       	</div>
			       	<div class="clear"></div>

			       	<div class="form">
				        <div class="col1">비밀번호</div>
				        <div class="col2">
							<input type="password" name="pass">
				        </div>
			       	</div>
			       	<div class="clear"></div>
			       	<div class="form">
				        <div class="col1">비밀번호 확인</div>
				        <div class="col2">
							<input type="password" name="pass_confirm">
				        </div>
			       	</div>
			       	<div class="clear"></div>
			       	<div class="form">
				        <div class="col1">이름</div>
				        <div class="col2">
							<input type="text" name="name">
				        </div>
			       	</div>
			       	<div class="clear"></div>
			       	<div class="form email">
				        <div class="col1">이메일</div>
				        <div class="col2">
							<input type="text" name="email1">@<input type="text" name="email2">
				        </div>
			       	</div>
			       	<div class="clear"></div>
			       	<div class="bottom_line"> </div>
			       	<div class="buttons">
	                	<img style="cursor:pointer" src="button_save.gif" onclick="check_input()">&nbsp;
                  		<img id="reset_button" style="cursor:pointer" src="button_reset.gif"
                  			onclick="reset_form()">
	           		</div>
           	</form>
        	</div> <!-- join_box -->
        </div> <!-- main_content -->
	</section>
	<footer>
    	<?php include "footer.php";?>
    </footer>
</body>
</html>
