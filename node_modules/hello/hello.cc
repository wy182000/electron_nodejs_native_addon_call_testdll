#include <node.h>
#include <v8.h>
#include "testdll.h"

using namespace v8;
#pragma comment(lib, "testdll.lib")

void Method(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  Local<String> value = String::NewFromUtf8(isolate, " nodejs native hello world \n");
  value = String::Concat(value, String::NewFromUtf8(isolate, CHello::Hello()));
  value = String::Concat(value, String::NewFromUtf8(isolate, func_hello()));
  args.GetReturnValue().Set(value);
}

void Init(Handle<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  exports->Set(String::NewFromUtf8(isolate, "hello"),
      FunctionTemplate::New(isolate, Method)->GetFunction());
}

NODE_MODULE(hello, Init)
