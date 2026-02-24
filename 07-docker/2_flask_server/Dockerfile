FROM python:3.9.16

COPY requirements.txt .

RUN pip3 install -r requirements.txt

WORKDIR /app

COPY app.py ./

COPY templates/* ./templates/ 

EXPOSE 5000

ENV BACKGROUND_COLOR=yellow

CMD ["python3", "./app.py"]
