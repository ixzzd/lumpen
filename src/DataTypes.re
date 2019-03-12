type city = {
  id: int,
  name: string,
};

type cities = list(city);

type modelImage = {
  normal: string,
  og: string,
};

type model = {
  id: int,
  name: string,
  city: string,
  avatar: modelImage,
};

type models = list(model);
