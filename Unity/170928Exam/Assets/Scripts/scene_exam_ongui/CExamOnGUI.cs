using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CExamOnGUI : MonoBehaviour {

    string mInputString = "";
    public Vector2 mScrollPosition = Vector2.zero;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    void OnGUI()
    {
        GUI.Label(new Rect(0, 0, 240, 100), "this is TextAlignment For test OnGUI");

        if(true == GUI.Button(new Rect(0,100,240,100), "TestButton" ))
        {
            Debug.Log("TestButton is Clicked");
        }

        mInputString = GUI.TextField(new Rect(0, 200, 240, 100), mInputString);
        //Debug.Log(mInputString);


        mScrollPosition = GUI.BeginScrollView(new Rect(0, 300, 240, 500), 
            mScrollPosition, new Rect(0, 0, 480, 800));

        GUI.Button(new Rect(0, 0, 50, 50), "TOP - left");
        GUI.Button(new Rect(480-50, 0, 50, 50), "TOP - right");
        GUI.Button(new Rect(0, 800-50, 50, 50), "Bottom - left");
        GUI.Button(new Rect(480-50, 800-50, 50, 50), "Bottom - right");

        GUI.EndScrollView();
    }





}
