import UIKit
import FirebaseCore
import FirebaseFirestore
import FirebaseAuth


class RegisterViewController: UIViewController {

    @IBOutlet weak var emailTextfield: UITextField!
    @IBOutlet weak var passwordTextfield: UITextField!
    
    
        @IBAction func registerPressed(_ sender: UIButton) {
            //if para verificar se a constante nao está vazia
            if let email = emailTextfield.text, let password = passwordTextfield.text {
                Auth.auth().createUser(withEmail: email, password: password) { authResult, error in
                    if let e = error {
                        print("register view controller\(e.localizedDescription)")
                    } else {
                        //navigate to controller
                        self.performSegue(withIdentifier: K.registerSegue, sender: self)
                    }
                }
            }
        
        }
    
}
