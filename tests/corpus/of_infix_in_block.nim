proc f() =
  runnableExamples:
    type
      Base = ref object of RootObj
      Sub1 = ref object of Base
    var base: Base = Sub1()
    doAssert base of Base # trailing comment
