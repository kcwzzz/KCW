using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//for EditorWindow
using UnityEditor;


/*
	created by pokpoongryu

	사용자정의된 확장 윈도우를 만들려면 
	EditorWindow를 상속받기만 하면 된다.

	Show(),
	OnEnable()
	OnGUI()
	를 만들어주자.
 */
public class CExamEditor : EditorWindow
{


    string mInputString = "";

    bool mIsFoldout = false;


    //유니티에디터에 해당 메뉴가 나타나게 한다.
    [MenuItem("CExamEditor/Show CExamEditor")]
    public static void Show()
    {

        EditorWindow.GetWindow(typeof(CExamEditor));

        EditorApplication.update();
    }

    void OnEnable()
    {

        Debug.Log("CExamEditor.OnEnable");
    }

    //해당 윈도우에 GUI들을 여기서 랜더링한다. 
    void OnGUI()
    {

        /* 
			//label
			GUI.Label(new Rect(0,0,240,100), "this is text for test OnGUI.");
			
			//button
			if( true == GUI.Button(new Rect(0,100,240,100), "TestButton") )
			{
				Debug.Log("TestButton is clicked.");
			}

			//textfield
			mInputString = GUI.TextField(new Rect(0,200,240,100), mInputString);
			Debug.Log(mInputString);
		*/



        EditorGUILayout.BeginVertical();

        if (true == GUILayout.Button("TestGUILayoutButton_0", GUILayout.Width(240), GUILayout.Height(50)))
        {
        }

        //EditorGUILayout.Space();
        GUILayout.Space(10);

        if (true == GUILayout.Button("TestGUILayoutButton_1", GUILayout.Width(240), GUILayout.Height(50)))
        {
        }

        EditorGUILayout.EndVertical();



        //GUILayout.Space(50);



        mIsFoldout = EditorGUILayout.Foldout(mIsFoldout, "Test Foldout");
        if (true == mIsFoldout)
        {
            EditorGUILayout.BeginVertical();

            //label
            int ti = 0;
            for (ti = 0; ti < 5; ti++)
            {
                EditorGUILayout.LabelField("LabelField_" + ti.ToString(), EditorStyles.helpBox);
            }

            //button
            if (true == GUILayout.Button("Button", EditorStyles.miniButton, GUILayout.Width(100), GUILayout.Height(20)))
            {

            }

            //textfield
            mInputString = EditorGUILayout.TextField(mInputString);

            EditorGUILayout.EndVertical();
        }


    }
}