<%-- 
    Document   : index
    Created on : 2021. 5. 22., 오전 12:18:14
    Author     : yejin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.net.URLEncoder" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<c:set value="C:/temp/download/a/" var ="targetDirectory"/>
<jsp:useBean id="fileList" scope="page" class="cse.my_name.ood_ch08.beans.FileListBean"/>
<jsp:setProperty name="fileList" property="dirName" value="${targetDirectory}"/>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>필터링 실습</title>
    </head>
     <body>
        <h1>파일 내려 받기</h1>
        <hr/>
        원하는 파일 선책하세요<br/><br/>
    
        <form method="POST" action="download.do">
            <c:forEach var="fileName" items="${fileList.relativeFileList}" > <!-- 보여지는 부분-->
                <input type ="radio" name="file_name" value="${fileName}"/> ${fileName} <br>
            </c:forEach>
            <br/>
            <input type="hidden" name="dirName" value="${targetDirectory}"/>
            <input type="submit" value="내려 받기"/>
        </form>
    </body>

</html>
