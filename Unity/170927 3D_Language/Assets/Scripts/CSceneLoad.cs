using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using UnityEngine.SceneManagement;

public class CSceneLoad : MonoBehaviour
{

    // Use this for initialization
    void Start()
    {
        CRyuSoundMgr.GetInst().CreateRyu();
        CRyuSoundMgr.GetInst().SetAudioBundle(FindObjectOfType<CAudioBundle>());
        CRyuSoundMgr.GetInst().BuildRyu();

        CRyuGameDataMgr.GetInst().CreateRyu();


        CRyuGameDataMgr.GetInst().SetSceneNum(0);

        SceneManager.LoadScene("CSceneTitle");
    }

    // Update is called once per frame
    void Update()
    {

    }
}
