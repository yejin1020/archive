/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cse.my_name.ood_ch07;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.List;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

/**
 *
 * @author yejin
 */

public class Uploadfile extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    private final String UPLOAD_DIR = "WEB-INF/upload/";
    private final String UPLOAD_TEMP_DIR = "WEB-INF/temp/";
    private final int MAX_MEMORY_SIZE = 10*1024*1024;
    private final int MAX_UPLOAD_SIZE = 20*1024*1024;
    
    private void checkFolder(String baseFolder){
        System.out.println("baseFolder = "+ baseFolder);
        
        File uf = new File(baseFolder + UPLOAD_DIR);
        if( !uf.exists()){
            uf.mkdir();
        }
        
        File tf = new File(baseFolder + UPLOAD_TEMP_DIR);
        if(!tf.exists()){
            tf.mkdir();
        }
    }
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
               
        try ( PrintWriter out = response.getWriter() ) {
            String currentFolder = this.getServletContext().getRealPath("/");
            out.println("currnet path =" + currentFolder + "(should be deleted) <br>");

            if(currentFolder.matches(".*\\.*")){
                currentFolder = currentFolder.replace("\\","/");
            }
           
            checkFolder(currentFolder);
            
            request.setCharacterEncoding("UTF-8");
            DiskFileItemFactory diskFactory = new DiskFileItemFactory();
            diskFactory.setSizeThreshold(MAX_MEMORY_SIZE);
            diskFactory.setRepository(new File(UPLOAD_TEMP_DIR));

            ServletFileUpload upload = new ServletFileUpload(diskFactory);
            upload.setSizeMax(MAX_UPLOAD_SIZE);
            try{
                
                List fileItems = upload.parseRequest(request);
                Iterator i = fileItems.iterator();
                
                while( i.hasNext()){
                    
                    FileItem fi = (FileItem)i.next();
                    out.println("Content type = " + fi.getContentType());
                    
                    if(fi.isFormField()){
                        out.println("filename = "+fi.getFieldName());
                        out.println(":" + fi.getString("UTF-8") + "<br>");
                        
                    }
                    else{
                        String fileName = fi.getName(); 
                        if(fileName != null && !fileName.equals("") ) {
                            out.println("file name  = " + fi.getName());
                            File file = new File(currentFolder + UPLOAD_DIR + fileName );
                            out.printf("파일 저장 경로 = %s <br>",file.getCanonicalPath());
                            fi.write(file);
                        }else {
                            out.println("파일 이름이 없습니다.");
                        }
                     }
                }
            }catch (Exception ex){
                    out.println("Cannot uploadfile : " + ex); 
            }finally{
                    out.close();
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
