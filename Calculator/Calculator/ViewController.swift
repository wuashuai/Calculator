//
//  ViewController.swift
//  Calculator
//
//  Created by wuzhongru on 9/10/16.
//  Copyright © 2016 wuzhongru. All rights reserved.
//

import UIKit
//import Foundation

class ViewController: UIViewController {

    @IBOutlet weak var numberDisplayLabel: UILabel!
    
//    var preValue = ""
//    var current = ""
//    var op = ""
//    var pos : Double = 1
//    var show = "0"
    
    
    @IBAction func numPadPressed(_ sender: UIButton) {
        
        let keyValue = sender.titleLabel!.text!
//        numberDisplayLabel.text = numPadPress(keyValue)
        numberDisplayLabel.text = String(getOne())
//        switch keyValue {
//            case "+","-","*","/" :
//                
//                if pos == 0{
//                    current = preValue
//                }
//                if pos != 0 && !preValue.isEmpty && !current.isEmpty {
//                    current = calculate(preValue, y: current, op: op)
//                }
//                
//                op = keyValue
//                preValue = current
//                show = preValue
//                current = ""
//                pos = 1;
//                if preValue == "error"{
//                    clear()
//                }
//            
//            case "AC": clearAll()
//            
//            case "+/-":
//                        if pos == 1 {
//                            current = reverse(current)
//                            show = current
//                        }
//                        else{
//                            preValue = reverse(preValue)
//                            show = preValue
//                        }
//            
//            case "%":
//                    if pos == 0{
//                        preValue = calculate(preValue, y: "100", op: "/")
//                        show = preValue
//                    }else{
//                        current = calculate(current, y: "100", op: "/")
//                        show = current
//                    }
//            
//            case "=":
//                
//                preValue = calculate(preValue, y : current, op : op)
//                pos = 0
//                show = preValue
//                if preValue == "error"{
//                    clear()
//                }
//            
//            case ".":
//                if current == "0" || pos == 0{
//                    current = "0."
//                    pos = 1
//                }
//                if !check(current) {
//                    current += keyValue
//                }
//                show = current
//            default :
//                if  pos == 0{
//                    op = ""
//                    pos = 1
//                    preValue = ""
//                    current = keyValue
//                }else if current == "0"{
//                    current = keyValue
//                }else{
//                    current += keyValue
//                }
//                show = current
//            }
//        
//        numberDisplayLabel.text = show;
        
    }
//    
//    func check(_ current : String) -> Bool{
//        return current.contains(".")
//        
//    }
//    
//    func reverse(_ current : String) -> String{
//        let re = "-1"
//        return calculate(current, y : re, op : "*")
//    }
//    
//    
//    func clearAll(){
//        preValue = ""
//        current = ""
//        op = ""
//        pos = 1
//        show = "0"
//    }
//    
//    func clear(){
//        preValue = ""
//        current = ""
//        op = ""
//        pos = 1
//    }
//    
//    func calculate(_ x : String, y : String, op : String) -> String{
//        var res : Double = 0
//        var alt : Int = 0
//        
//        var a = 0.0
//        var b = 0.0
//        
//        if x != "." && x != ""{
//            a = Double (x)!
//        }
//        if y != "." && y != ""{
//            b = Double (y)!
//        }
//
//
//        switch op {
//        case "+": res = a + b
//        case "-": res = a - b
//        case "*": res = a * b
//        case "/":
//            if b == 0 {
//                return "error"
//            }
//            res = a / b
//        default:
//            res = a + b
//        }
//        alt = Int (res)
//        if Double (alt) == res{
//            return alt.description
//        }
//        
//        return res.description
//    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

