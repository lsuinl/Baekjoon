
var a='hello world'; //변수
let aa='hello world'; //가변형 지역 변수
const aaa='hello world'; //불변형 지역 변수
//----------------------
a=a+1; a+=1; //전자 사용 금지?
var plus = a+aa; //문자열 이어붙이기
//-------------
console.log("안뇽"); //출력
//------------------
if(a>aa){ //조건문
}
else if(a<aa){
}
//-----------------
function suin(ahri){  //함수 선언
    console.log(ahri);
}

// var suin=function(ahri){  //선언 방법2
//     console.log(ahri);
// }

// var suin = () => {  //선언 방법 3
//     console.log(ahri);
// }

suin('아리 시끄러..'); //함수 호출
//-----------------------
function add(b,c){ //값 반환 함수 
    return b+c;
}

// var add(b,c)=> b+c; //선언 방법 2

var b=10;
var c=20;
console.log(add(b,c)); //함수 호출
//------------------------
var arr=new Array(); //배열 선언
var arr=[];

var arr=["a",'b',"c"]; //값 삽입 1
arr[0]="a"; //2
arr.push(a); //3 (puch시 비어있는 배열에 값을 넣어줌 아닌가? 맞을걸)
//-----------------------
console.log(arr.length); //배열의 길이
console.log(arr.join(", ")); //join: 배열을 붙여 하나의 문자열로 만들어줌
console.log(arr.reverse()); //배열을 반대로 뒤집음
console.log(arr.sort()) //배열 정리(괄호 안에 정렬 방식 기입)

arrr=["d","e","f"];
console.log(arr.concat(arrr)); //두 배열 합치기
//----------------------
var obj =new Object(); //오브젝트 선언
var obj ={};

obj.su=10; //오브젝트에 변수
obj.in=20;

var obj ={
    su: 10,
    in: 20
};

//?? 오브젝트 할당

for(var i=0; i<5; i++){ //for문
    console.log(i);
}

var arr=[10,20,30,40,50];
for(var i in arr) { //배열로 for문(오브젝트의 키 개수로도 가능)
    console.log(i);
}

for(var i of arr) { //i에 배열의 값을 할당(in은 순서 0,1,2할당)
    console.log(i);
}

var i=0;
while(i<5){ //while문
    console.log(i);
    i++;
}
//-----------------------------------
