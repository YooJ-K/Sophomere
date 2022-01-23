$(function(){
var state = false;
$(".open_bt").click(function(){
$(".all_menu").stop().slideToggle("fast");
//1. 전체 메뉴가 보이고 사라지는 토글 기능

if(!state){ //true
  imgOff(this);	//this = a태그의 open_bt
  state = true;	// 교체작업 완료
}else{		//false
  imgOn(this);
  state = false;
}
return false;
});
function imgOff(t){	//열기에서 닫기로 이미지 변환
var img = $(t).find("img");
img.attr("src",img.attr("src").replace("on","off")).attr("alt","MENU");
}
function imgOn(t){	//닫기에서 열기로 이미지 변환
var img = $(t).find("img");
img.attr("src",img.attr("src").replace("off","on")).attr("alt","MENU");
}
//2. [전체메뉴열기] 이미지가 [전체메뉴닫기] 이미지로 토글 기능
$(".close_bt").on("click blur",function(){
$(".all_menu").stop().slideUp("fast");
imgOn(".open_bt");
state = false;
});//3. [닫기] 이미지 클릭시 전체메뉴 사라지는 기능

});
