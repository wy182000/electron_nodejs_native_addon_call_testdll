{
  "targets": [
    {
     "target_name": "hello",
      "sources":[ "hello.cc" ],
      "libraries": [],
       "conditions": [
        [
          "OS=='win'",
          {
            "link_settings": {
              "libraries": [
                "-l../testdll.lib",
               ]
            }
          }
        ]
      ]
    }
  ]
}
