<%-- 
    Document   : index
    Created on : 2021. 5. 19., 오후 3:08:52
    Author     : yejin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Commons Logging</title>
    </head>
    <body>
        <h1>이름과 나이를 입력하세요</h1>
        
        <form action="logging2.do" method="POST">
            이름 : <input type="text" name="name" value="" size="20" /> <br/>
            나이 : <input type="text" name="age" value="" size="20" /> <br/>
            <input type="submit" value="저장" /> <input type="reset" value="원래대로"/>
        </form>
    </body>
</html>
