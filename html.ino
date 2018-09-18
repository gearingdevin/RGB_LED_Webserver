


String htmlGet(){

  String web_html =  R"=====(
  <!DOCTYPE html>
<html>
 <head>
 <meta name='viewport' content='width=device-width, initial-scale=1.0'/>
 <meta charset='utf-8'>
 <title>LED Control</title>
</head>
<body onload="pageStart()">
 <div id='main'>
  <h2>LED Control</h2>
  <input type='button' id = 'LED_button' onclick='switchLED()' value='OFF' class=''  /> 
  <fieldset class="topSpace whiteBorder" id="controlCenter">
    <legend>Control Center</legend><br>
      <label id="sliderBrightnessLabel"for="sliderBrightness" class="margin">Brightness:</label>
      <input type='range' id='sliderBrightness' name='Bright_Slider' min='100' max='355' value='250' style='width: 60vw' oninput='changeBrightness(this.value)'>
      <br>
      <br>
      <label id ="sliderRed" for="Red_Slider" class="margin">Red:</label>
      <input type='range' id='Red_Slider' name='Red_Slider' min='100' max='355' value='250' style='width: 60vw' oninput='changeRed(this.value)'>
      <br>
      <br>
      <label id ="sliderGreen" for="Green_Slider" class="margin">Green:</label>
      <input type='range' id='Green_Slider' name='Green_Slider' min='100' max='355' value='250' style='width: 60vw' oninput='changeGreen(this.value)'>
      <br>
      <br>
      <label id ="sliderBlue" for="Blue_Slider" class="margin">Blue:</label>
      <input type='range' id='Blue_Slider' name='Blue_Slider' min='100' max='355' value='250' style='width: 60vw' oninput='changeBlue(this.value)'>
  </fieldset>
  <div>

      <!-- THINGS ENCLOSED IN THIS ARE COMMENETED OUT RAINBOW MODE NOT FULLY WORKING  -->
    <!--   <input type="button" id = "Rainbow_button" onclick="rainbowEffect()" value="Rainbow" class=""/> -->
      
  </div>
  <p id = "reply">Reply appears here</p>
 </div>
</body>
</html>
  )=====";



  

String web_compiled =  cssGet() + javascriptGet()+ web_html;
  
  
  return web_compiled;
  }
