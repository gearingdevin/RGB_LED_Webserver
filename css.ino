


String cssGet(){
  String web_css = R"=====(
<style>
  body {font-size:140%;} 
  #main {display: table; margin: auto; width:70%;  padding: 0 10px 0 10px; color: white; } 
  h2 {text-align:center; color: white; } 
  h4 {text-align:center; margin-bottom: 0px; color: white;}
  #LED_button { padding:10px 10px 10px 10px; width:100%; font-size: 120%; color: white; border-width: 2px;border-style: solid; border-radius: 4px;}
  #Rainbow_button { padding:10px 10px 10px 10px;margin-top: 10px; width:50%; font-size: 120%; color: white; border-width: 2px;border-style: solid; border-radius: 4px;}
  .Off_Button {border-color: white !important; background-color: rgba(255,255,255,0.0)} 
  .On_Button {border-color: white !important; background-color: rgba(255,255,255,0.5)}
  input[type="range"]:disabled { opacity: 0.5;}
  input[type="range"]{ vertical-align:middle; background-color: rgba(255,255,255,0.5);}
  input[type="button"]{ border-width: 0px;-webkit-appearance: none; -moz-appearance: none; appearance: none;}
  .whiteBorder {border-style: solid; border-color: white; border-radius: 4px; margin-left: 0px; margin-right: 0px;}

  textarea:focus, input:focus{ outline: none; }
  .disabled { opacity: 0.5;}
  label { }
  legend {border-color: white !important;}
  .topSpace { margin-top: 15px; color: white;}
  body{
    background: -webkit-linear-gradient(left, #25c481, #25b7c4);
    background: linear-gradient(to right, #25c481, #25b7c4);
    font-family: 'Roboto', sans-serif;
  }
  fieldset > * {
    vertical-align: middle;
    display: table-cell;
    border-color: white;
    
  }
  .slidecontainer {
    width: 100%;
    padding-top: 20px;
    padding-bottom: 20px;
  }
  .slider {
    -webkit-appearance: none;
    width: 100%;
    height: 15px;
    border-radius: 5px;
    background: #d3d3d3;
    outline: none;
    opacity: 1;
}

.textFlash {
    
    animation: flash 2s linear infinite;
}

@keyframes flash {
    0% {  color: rgba(255,255,255,1); }
    50% {  color: rgba(255,255,255,0.1); }
    100% {  color: rgba(255,255,255,1); }
}

 </style>

   )=====";
   return web_css;
  }
