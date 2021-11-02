<%-- 
    Document   : index
    Created on : 2021. 5. 11., 오후 7:36:15
    Author     : yejin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>File upload</title>
        <script typr ='text/javascript'>
                function check_file_size(){
                    var size_limit = 20*1000*1000;
                    var file = document.getElementById('file_input').files[0];
                    alert('Upload file name =' + file.name + ", file size =" +
                            file.size.toString().replace(/\B(?=(\d{3})+(?1\d))/g,"," + "바이트");
                    if( file.size > size_limit){
                        alert('cannit upload the file because of File size > 20MB');
                        return false;
                        
                    }else {
                        return true;
                    }
                }
        </script>
    </head>
    <body>
        <form enctype="multipart/form-data" method="POST" action="Uploadfile.do" onsubmit="return check_file_size()">
            username: <input type="text" name="username"> <br>
            upload할 파일 선택: <input type="file" name="upfile" id="file_iput"> <br>
            <input type="submit" value="Upload">     
        </form>
    </body>
</html>
