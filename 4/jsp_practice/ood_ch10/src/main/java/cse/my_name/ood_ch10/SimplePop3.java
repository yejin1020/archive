/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cse.my_name.ood_ch10;

import com.sun.mail.pop3.POP3Store;
import com.sun.mail.pop3.POP3Folder;
import java.util.Properties;
import javax.mail.Session;
import javax.mail.Address;
import javax.mail.Folder;
import javax.mail.Message;
import javax.mail.Transport;
import javax.mail.internet.MimeMessage;

public class SimplePop3 {
    public static void main(String[] args){
        
        StringBuffer out = new StringBuffer();
        
        try{
            
            String host ="localhost";
            String user ="a";
            String passwd ="a";
            
            Properties props = System.getProperties();
            props.setProperty("mail.pop3.host",host);
            props.setProperty("mail.pop3.user",user);
            props.setProperty("mail.pop3.apop.enable","true");
            props.setProperty("mail.debug","true");
            
            Session session = Session.getInstance(props);
            
            POP3Store store = (POP3Store)session.getStore("pop3");
            store.connect(host,user,passwd);
            if(!store.isConnected()){
                System.err.println("POP3 connection failed");
                return;
            }
            
            POP3Folder folder = (POP3Folder)store.getFolder("INBOX");
            folder.open(Folder.READ_ONLY);
            
            Message[] msgs = folder.getMessages();
            int nth =1;
            for( Message msg : msgs){
                MimeMessage mimeMsg = (MimeMessage)msg;
                out.append("<" + nth++ +"번째 메일 : UID ="
                + folder.getUID (mimeMsg) + ">\n" );
                out.append("From:" + mimeMsg.getFrom()[0].toString() + "\n");
                out.append("Date :" + mimeMsg.getSentDate()+ "\n");
                out.append("Subject: "+ mimeMsg.getSubject()+"\n\n");
                
            }
            
            folder.close(true);
            store.close();
            
            
                    
        }catch(Exception ex){
            ex.printStackTrace();
    
        }
        System.out.println(out.toString());
    }
    
    
    
}
