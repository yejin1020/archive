package cse.my_name.ood_ch07.file_download.control;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.URLEncoder;
import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author yejin
 */
public class DownloadServlet_fast extends HttpServlet{
    

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        
         request.setCharacterEncoding("UTF-8");
        response.setContentType("application/octet-stream");

        String selectedFile = request.getParameter("D1");
        String targetDirectory = request.getParameter("dirName");

        File f = new File(targetDirectory + selectedFile);
        try (BufferedInputStream bis = new BufferedInputStream(new FileInputStream(f))){
            response.setHeader("Content-Disposition","inline; filename="+URLEncoder.encode(selectedFile,"utf-8"));
                try(ServletOutputStream sos = response.getOutputStream()){
                  byte[] buf = new byte[1024]; // 이방법은 속도가 allbytes를 하는 방법보다 느리나 다운로드 실행이 바로 동작된다
                    while (bis.available() > 0) {
                        //sos.write(bis.read());
                        int n = bis.read(buf); //
                        sos.write(buf,0,n);
                        //sos.write(bis.readAllBytes());

                       }
                } 


        }
        
    }
       
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>


}