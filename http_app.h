static const char PROGMEM INDEX_HTML[] = R"rawliteral(
<html>
  <head>
    <title>ESP32 Soil Microbiome Sensor</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body { font-family: Arial; text-align: center; margin:0px auto; padding-top: 30px;}
      table { margin-left: auto; margin-right: auto; }
      td { padding: 8 px; }
      .button {
        background-color: #2f4468;
        border: none;
        color: white;
        padding: 10px 20px;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        font-size: 18px;
        margin: 6px 3px;
        cursor: pointer;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: rgba(0,0,0,0);
      }
      img {  width: auto ;
        max-width: 100% ;
        height: auto ; 
      }
    </style>
  </head>
  <body>
    <h1>ESP32 Soil Microbiome Monitoring</h1>
    <img src="" id="photo" >
    
    <div align="center">
      <button class="button" onclick="startStream('start');">START</button>
      <button class="button" onclick="startStream('stop');">STOP</button>
      <button class="button" onclock="getStill()">Get Still</button>
    </div>

    <form onsubmit="timelapse();return false">
      <label">Wait Duration (sec):</label>
      <input type="integer" id="duration"></input>
      <label>Total Number of Photo:</label>
      <input type="integer" id="num"></input>
      <input type="submit"></input>
    </form>

    <table>
      <tr>
        <td>Quality</td> <td colspan="2"><input type="range" id="quality" min="10" max="63" value="10" onchange="control(this.id, this.value)"></td>
      </tr>
      
      <tr>
        <td>Brightness</td> <td colspan="2"><input type="range" id="brightness" min="-2" max="2" value="0" onchange="control(this.id, this.value)"></td>
      </tr>
      
      <tr>
        <td>Contrast</td> <td colspan="2"><input type="range" id="contrast" min="-2" max="2" value = "0" onchange="control(this.id, this.value)"></td>
      </tr>
    </table>
    
   <h3 id="output"><h3>
   
   <script>
   function timelapse(){
    dur = document.getElementById("duration").value;
    num = document.getElementById("num").value;
    var xhr = new XMLHttpRequest();
    document.getElementById("output").innerText = "Period (msec):" + String(dur) +" Total Number of photo:" + String(num);
    xhr.open("GET", "/control?" + "var=timeLapse" + "&val1=" + String(dur) + "&val2=" + String(num), true);
    xhr.send();
   }
   
   function control(id, value){
    var xhr = new XMLHttpRequest();
    document.getElementById("output").innerText = String(id) +"= " + String(value);
    xhr.open("GET", "/control?" + "var=" + String(id) + "&val1=" + String(value), "&val2=", true);
    xhr.send();
   }
   
   function getStill(){
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/still", true);
    xhr.send();
   }

  function startStream(x) {
    if(x=='start'){
      document.getElementById("photo").src = window.location.href.slice(0, -1) + ":81/stream";
    }
    else if(x=='stop'){
      document.getElementById("photo").src = "";
    } 
  }
   
   window.onload = document.getElementById("photo").src = window.location.href.slice(0, -1) + ":81/stream";
  </script>
  
  </body>
</html>
)rawliteral";
