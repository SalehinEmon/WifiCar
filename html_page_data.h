String html = R"=====(<!--Version 1.1-->
<!DOCTYPE html>
<html>
<head>
        <style>
                .button {
                        background-color: #f44336; /* Red */
                        border: none;
                        color: white;
                        padding: 25px 42px;
                        text-align: center;
                        text-decoration: none;
                        display: inline-block;
                        font-size: 16px;
                        margin: 4px 2px;
                        cursor: pointer;
                        }
           
        </style>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Wifi car Control panel</title>
</head>
<body>
    <table align="center">
        <tr>
            <td></td>
            <td><input type="button" class="button" value="Up" onmousedown="FrontButton()" onmouseup="StopButton()" id="FrontButton" ></td>
            <td></td>
        </tr>
        <tr>   
            <td><input type="button" class="button" value="Left" onmousedown="LeftButton()" onmouseup="StopButton()" id="LeftButton" ></td>
            <td></td>
            <td><input type="button" class="button"  value="Right" onmousedown="RightButton()" onmouseup="StopButton()" id="RightButton" ></td>
        </tr>
        <tr>
            <td></td>
            <td><input type="button" class="button"  value="Back" onmousedown="BackButton()" onmouseup="StopButton()" id="BackButton" ></td>
            <td></td>
        </tr>
    </table>

    <h3 id="output"></h3>

    <script>
        window.addEventListener("keydown",KeyPressEvent,false);
        window.addEventListener("keyup",KeyReleaseEvent,false);

        document.getElementById("FrontButton").addEventListener('pointerdown',FrontButton,false);
        document.getElementById("LeftButton").addEventListener('pointerdown',LeftButton,false);
        document.getElementById("RightButton").addEventListener('pointerdown',RightButton,false);
        document.getElementById("BackButton").addEventListener('pointerdown',BackButton,false);

        document.getElementById("FrontButton").addEventListener('pointerup',StopButton,false);
        document.getElementById("LeftButton").addEventListener('pointerup',StopButton,false);
        document.getElementById("RightButton").addEventListener('pointerup',StopButton,false);
        document.getElementById("BackButton").addEventListener('pointerup',StopButton,false);


        function FrontButton()
            {
                console.log("Front Button pressed");                
                var xhttp = new XMLHttpRequest();

                xhttp.onreadystatechange = function() 
                {
                    if (this.readyState == 4 && this.status == 200) 
                    {
                        document.getElementById("output").innerHTML = this.responseText;
                    }
                };

                xhttp.open("GET", "up", true);
                xhttp.send();

    
            }

        function BackButton()
            {
                console.log("Front Button pressed");
                
                var xhttp = new XMLHttpRequest();

                xhttp.onreadystatechange = function() 
                {
                    if (this.readyState == 4 && this.status == 200) 
                    {
                        document.getElementById("output").innerHTML = this.responseText;
                    }
                };

                xhttp.open("GET", "back", true);
                xhttp.send();

    
            }

        function LeftButton()
            {
                console.log("left Button pressed");
                
                var xhttp = new XMLHttpRequest();

                xhttp.onreadystatechange = function() 
                {
                    if (this.readyState == 4 && this.status == 200) 
                    {
                        document.getElementById("output").innerHTML = this.responseText;
                    }
                };

                xhttp.open("GET", "left", true);
                xhttp.send();
                
    
            }
        function RightButton()
            {
                console.log("Rignt button pressed");
                var xhttp = new XMLHttpRequest();

                xhttp.onreadystatechange = function() 
                {
                    if (this.readyState == 4 && this.status == 200) 
                    {
                        document.getElementById("output").innerHTML = this.responseText;
                    }
                };

                xhttp.open("GET", "right", true);
                xhttp.send();
                
    
            }
        function StopButton()
            {
                console.log("Stop button pressed");
                var xhttp = new XMLHttpRequest();

                xhttp.onreadystatechange = function() 
                {
                    if (this.readyState == 4 && this.status == 200) 
                    {
                        document.getElementById("output").innerHTML = this.responseText;
                    }
                };


                xhttp.open("GET", "stop", true);
                xhttp.send();
                
    
            }


        function KeyPressEvent(e)
        {
            //document.getElementById("output").innerHTML = e.code;

            if(e.code === "ArrowUp" || e.code === "KeyW")
            {
                FrontButton();
            }
            else if(e.code === "ArrowDown" || e.code ===  "KeyS")
            {
                BackButton();
            }
            else if(e.code === "ArrowRight" || e.code ===  "KeyD")
            {
                RightButton();
            }
            else if(e.code === "ArrowLeft" || e.code ===  "KeyA")
            {
                LeftButton();
            }
        }

        function KeyReleaseEvent(e)
        {
            if(e.code === "ArrowUp" || e.code === "ArrowDown" || e.code === "ArrowRight"  || e.code === "ArrowLeft" ||e.code === "KeyW" || e.code === "KeyA" || e.code === "KeyS" || e.code === "KeyD" || e.code === "Space")
            {
                StopButton();
            }
        }
    </script>


</body>
</html>)=====";
