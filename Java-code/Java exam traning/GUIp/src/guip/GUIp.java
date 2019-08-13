/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package guip;

import java.awt.EventQueue;
import javax.swing.JFrame;
public class GUIp {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				 NewJFrame frame=new NewJFrame();
			    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			    frame.setVisible(true);		
			}
		});
    }
    
}

