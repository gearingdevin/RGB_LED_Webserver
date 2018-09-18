
String javascriptGet(){
  
String web_javascript = R"=====(

<script>

//var slider = document.getElementById("sliderBrightness");
//slider.oninput = function() {
//    output.innerHTML = this.value;
//}
var effect = "null";
var isOn = "false";
var delayAmount = 140;


function pageStart(){
  var l_status = document.getElementById("LED_button").value;
   if(l_status=="OFF"){
      document.getElementById("LED_button").classList.add("Off_Button");
      document.getElementById("LED_button").classList.remove("On_Button");
     // document.getElementById("Rainbow_button").classList.add("Off_Button");
      //document.getElementById("Rainbow_button").classList.remove("On_Button");
      disableSliders();
      ajaxLoad('LEDOFF');
   }
   if(l_status=="ON"){
      document.getElementById("LED_button").classList.add("On_Button");
      document.getElementById("LED_button").classList.remove("Off_Button");
      enableSliders();
    }
  }


  function disableSwitch(){
     document.getElementById("LED_button").classList.add("disabled");
     document.getElementById("LED_button").disabled = true;
    }

   function enableSwitch(){
     document.getElementById("LED_button").classList.remove("disabled");
     document.getElementById("LED_button").disabled = false;
    }

   function disableSliders(){
      document.getElementById("sliderBrightness").disabled = true;
      document.getElementById("sliderBrightnessLabel").classList.add("disabled");
      document.getElementById("Red_Slider").disabled = true;
      document.getElementById("sliderRed").classList.add("disabled");
      document.getElementById("Green_Slider").disabled = true;
      document.getElementById("sliderGreen").classList.add("disabled");
      document.getElementById("Blue_Slider").disabled = true;
      document.getElementById("sliderBlue").classList.add("disabled");
      document.getElementById("controlCenter").classList.add("disabled");
     }
     
   function enableSliders(){
      document.getElementById("sliderBrightness").disabled = false;
      document.getElementById("sliderBrightnessLabel").classList.remove("disabled");
      document.getElementById("Red_Slider").disabled = false;
      document.getElementById("sliderRed").classList.remove("disabled");
      document.getElementById("Green_Slider").disabled = false;
      document.getElementById("sliderGreen").classList.remove("disabled");
      document.getElementById("Blue_Slider").disabled = false;
      document.getElementById("sliderBlue").classList.remove("disabled");
      document.getElementById("controlCenter").classList.remove("disabled");
    }

    function switchLED() {
       
       var button_text = document.getElementById("LED_button").value;
       
     if (button_text=="OFF")
     {
       document.getElementById("LED_button").classList.add("On_Button");
       document.getElementById("LED_button").classList.remove("Off_Button");
       document.getElementById("LED_button").value = "OFF";
       enableSliders();
       ajaxLoad('LEDON'); 
     }
     if (button_text=="ON")
     {
       document.getElementById("LED_button").classList.add("Off_Button");
       document.getElementById("LED_button").classList.remove("On_Button");
       document.getElementById("LED_button").value = "ON";
       disableSliders();
       ajaxLoad('LEDOFF');
       
     }
    }

  function rainbowEffect(){
    //rainbow code still have come bugs so its disabled
    
//    if(effect == "null"){
//      disableSwitch();
//      document.getElementById("Rainbow_button").classList.add("textFlash");
//      effect = "rainbow";
//      ajaxLoad('Rainbow');
//    }
//    else{
//      enableSwitch();
//      document.getElementById("Rainbow_button").classList.remove("textFlash");
//      effect = "null";
//      ajaxLoad('Rainbow');
//     }
    
    }

  var holdTime=0;
  
  function startTimer(){
    var d = new Date();  // Possible memory leak?
    holdTime = d.getTime();
   }  

//  function delay(ms) {
//        var cur_d = new Date();
//        var cur_ticks = cur_d.getTime();
//        var ms_passed = 0;
//        while(ms_passed < ms) {
//            var d = new Date();  // Possible memory leak?
//            var ticks = d.getTime();
//            ms_passed = ticks - cur_ticks;
//            // d = null;  // Prevent memory leak?
//        }
//    }
    
    function changeBrightness(brightness) {
      var currentDate = new Date();
      var currentTime =  currentDate.getTime();
      if((currentTime - holdTime) > delayAmount){
           startTimer();
          ajaxLoad('Bright_'+brightness);
      }
      }
    function changeRed(level) {
      var currentDate = new Date();
      var currentTime =  currentDate.getTime();
      if((currentTime - holdTime) > delayAmount){
           startTimer();
          ajaxLoad('Red_'+level);
      }
      }
    function changeGreen(level) {
      var currentDate = new Date();
      var currentTime =  currentDate.getTime();
      if((currentTime - holdTime) > delayAmount){
           startTimer();
          ajaxLoad('Green_'+level);
      }
      }
    function changeBlue(level) {
      var currentDate = new Date();
      var currentTime =  currentDate.getTime();
      if((currentTime - holdTime) > delayAmount){
           startTimer();
          ajaxLoad('Blue_'+level);
      }
      }
    

var ajaxRequest = null;
if (window.XMLHttpRequest)  { ajaxRequest =new XMLHttpRequest(); }
else                        { ajaxRequest =new ActiveXObject("Microsoft.XMLHTTP"); }


function ajaxLoad(ajaxURL)
{
  if(!ajaxRequest){ alert("AJAX is not supported."); return; }
  
  ajaxRequest.open("GET",ajaxURL,true);
  ajaxRequest.onreadystatechange = function()
  {
    if(ajaxRequest.readyState == 4 && ajaxRequest.status==200)
    {
      holdTime = 0;
      var ajaxResult = ajaxRequest.responseText;
      if      ( ajaxResult == "LED is on" )   {
        document.getElementById("LED_button").value = "ON";
        }
        
      if      ( ajaxResult == "LED is off" )  {
        document.getElementById("LED_button").value = "OFF";
       
        }

//Brightness Change
        //actual ajaxResult is 'Bright XXX'
        if      ( ajaxResult == "Brightness Change" )  {
         //document.getElementById("reply").innerHTML = ajaxResult;
        } 
      
      document.getElementById("reply").innerHTML = ajaxResult;
    }
  }
  ajaxRequest.send();
}
   
</script>

)=====";

return web_javascript;
}

